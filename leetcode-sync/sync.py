"""
🟢 LeetCode Sync — Fully Automatic, Fully Private
Fetches your accepted LeetCode submissions and pushes them to a local Git repo.

✨ AUTO-COOKIE MODE: Extracts cookies directly from your Chrome browser.
   No manual copying. No third-party extensions. Zero maintenance.

Usage:
    1. Copy .env.example to .env and fill in USERNAME + REPO_PATH
    2. pip install -r requirements.txt
    3. python sync.py
       (Close Chrome first, or the script will prompt you)

Everything stays on YOUR machine. No third-party services.
"""

import os
import sys
import json
import time
import shutil
import pickle
import subprocess
import logging
import tempfile
from pathlib import Path
from datetime import datetime, timezone

import requests
from dotenv import load_dotenv

# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------

SCRIPT_DIR = Path(__file__).resolve().parent
load_dotenv(SCRIPT_DIR / ".env")

LEETCODE_USERNAME = os.getenv("LEETCODE_USERNAME", "")
GITHUB_REPO_PATH = os.getenv("GITHUB_REPO_PATH", "")

# Optional: manual cookies (fallback if auto-extract fails)
MANUAL_SESSION = os.getenv("LEETCODE_SESSION", "")
MANUAL_CSRF = os.getenv("LEETCODE_CSRF_TOKEN", "")

GRAPHQL_URL = "https://leetcode.com/graphql"
LAST_SYNC_FILE = SCRIPT_DIR / ".last_sync"
COOKIE_CACHE_FILE = SCRIPT_DIR / ".cookie_cache.pkl"
LOG_FILE = SCRIPT_DIR / "sync.log"

# Chrome profile path (auto-detected for Windows)
CHROME_USER_DATA = os.getenv(
    "CHROME_USER_DATA",
    str(Path.home() / "AppData" / "Local" / "Google" / "Chrome" / "User Data"),
)
CHROME_PROFILE = os.getenv("CHROME_PROFILE", "Default")

# Language slug → file extension mapping
LANG_EXTENSIONS = {
    "python": ".py",
    "python3": ".py",
    "cpp": ".cpp",
    "c": ".c",
    "java": ".java",
    "javascript": ".js",
    "typescript": ".ts",
    "csharp": ".cs",
    "go": ".go",
    "ruby": ".rb",
    "swift": ".swift",
    "kotlin": ".kt",
    "rust": ".rs",
    "scala": ".scala",
    "php": ".php",
    "dart": ".dart",
    "racket": ".rkt",
    "erlang": ".erl",
    "elixir": ".ex",
    "bash": ".sh",
    "mysql": ".sql",
    "mssql": ".sql",
    "oraclesql": ".sql",
    "postgresql": ".sql",
}

# ---------------------------------------------------------------------------
# Logging
# ---------------------------------------------------------------------------

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(message)s",
    handlers=[
        logging.FileHandler(LOG_FILE, encoding="utf-8"),
        logging.StreamHandler(sys.stdout),
    ],
)
log = logging.getLogger("leetcode-sync")

# ---------------------------------------------------------------------------
# Cookie Extraction from Chrome
# ---------------------------------------------------------------------------


def extract_cookies_from_chrome():
    """
    Launch Chrome with your existing profile via undetected-chromedriver,
    navigate to LeetCode, and extract session cookies automatically.

    Requires Chrome to be CLOSED (can't share profile with running instance).
    """
    log.info("🔑 Auto-extracting cookies from Chrome...")

    try:
        import undetected_chromedriver as uc
    except ImportError:
        log.error(
            "undetected-chromedriver not installed.\n"
            "Run: pip install undetected-chromedriver selenium"
        )
        return None, None

    chrome_data_path = Path(CHROME_USER_DATA)
    if not chrome_data_path.exists():
        log.error("Chrome user data not found at: %s", CHROME_USER_DATA)
        return None, None

    driver = None
    try:
        options = uc.ChromeOptions()
        options.add_argument(f"--user-data-dir={CHROME_USER_DATA}")
        options.add_argument(f"--profile-directory={CHROME_PROFILE}")
        # Run in background — no visible window
        options.add_argument("--headless=new")
        options.add_argument("--no-first-run")
        options.add_argument("--no-default-browser-check")
        options.add_argument("--disable-popup-blocking")

        log.info("  Launching Chrome (headless)...")
        driver = uc.Chrome(options=options, use_subprocess=True)

        log.info("  Navigating to LeetCode...")
        driver.get("https://leetcode.com/")
        time.sleep(3)  # Wait for page + cookies to load

        # Extract cookies
        cookies = driver.get_cookies()
        session_cookie = None
        csrf_cookie = None

        for cookie in cookies:
            if cookie["name"] == "LEETCODE_SESSION":
                session_cookie = cookie["value"]
            elif cookie["name"] == "csrftoken":
                csrf_cookie = cookie["value"]

        if session_cookie and csrf_cookie:
            log.info("  ✅ Cookies extracted successfully!")
            # Cache them so we don't need Chrome every time
            _save_cookie_cache(session_cookie, csrf_cookie)
            return session_cookie, csrf_cookie
        else:
            log.warning(
                "  ⚠️  Could not find LeetCode cookies. "
                "Are you logged into LeetCode in Chrome?"
            )
            return None, None

    except Exception as e:
        error_msg = str(e).lower()
        if "user data directory is already in use" in error_msg or "already running" in error_msg:
            log.error(
                "  ❌ Chrome is currently open. Please close ALL Chrome windows first,\n"
                "     then re-run this script. (Chrome locks its profile while running.)"
            )
        else:
            log.error("  ❌ Failed to extract cookies: %s", e)
        return None, None

    finally:
        if driver:
            try:
                driver.quit()
            except Exception:
                pass


def _save_cookie_cache(session, csrf):
    """Cache cookies locally so we don't need Chrome on every run."""
    cache = {
        "session": session,
        "csrf": csrf,
        "timestamp": int(time.time()),
    }
    with open(COOKIE_CACHE_FILE, "wb") as f:
        pickle.dump(cache, f)


def _load_cookie_cache():
    """Load cached cookies. Returns (session, csrf) or (None, None)."""
    if not COOKIE_CACHE_FILE.exists():
        return None, None
    try:
        with open(COOKIE_CACHE_FILE, "rb") as f:
            cache = pickle.load(f)
        # Cache is valid for 7 days
        age_days = (int(time.time()) - cache.get("timestamp", 0)) / 86400
        if age_days > 7:
            log.info("  Cookie cache expired (%d days old). Will refresh.", int(age_days))
            return None, None
        return cache.get("session"), cache.get("csrf")
    except Exception:
        return None, None


def get_cookies():
    """
    Get LeetCode cookies using this priority:
    1. Cached cookies (from previous Chrome extraction)
    2. Auto-extract from Chrome
    3. Manual cookies from .env (fallback)
    """
    # Try 1: Cached cookies
    session, csrf = _load_cookie_cache()
    if session and csrf:
        log.info("🔑 Using cached cookies (auto-extracted from Chrome)")
        return session, csrf

    # Try 2: Auto-extract from Chrome
    session, csrf = extract_cookies_from_chrome()
    if session and csrf:
        return session, csrf

    # Try 3: Manual cookies from .env
    if MANUAL_SESSION and MANUAL_CSRF:
        log.info("🔑 Using manual cookies from .env")
        return MANUAL_SESSION, MANUAL_CSRF

    log.error(
        "❌ No cookies available!\n"
        "   Option A: Close Chrome and re-run (auto-extract will work)\n"
        "   Option B: Run refresh-cookies.ps1 to set them manually"
    )
    return None, None


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------


def validate_config():
    """Ensure all required config values are present."""
    missing = []
    if not LEETCODE_USERNAME:
        missing.append("LEETCODE_USERNAME")
    if not GITHUB_REPO_PATH:
        missing.append("GITHUB_REPO_PATH")

    if missing:
        log.error(
            "Missing config in .env: %s\n"
            "Edit .env and fill in your details.",
            ", ".join(missing),
        )
        sys.exit(1)

    repo = Path(GITHUB_REPO_PATH)
    if not repo.exists():
        log.error("GITHUB_REPO_PATH does not exist: %s", GITHUB_REPO_PATH)
        sys.exit(1)
    if not (repo / ".git").exists():
        log.error("GITHUB_REPO_PATH is not a git repository: %s", GITHUB_REPO_PATH)
        sys.exit(1)


def get_session(session_cookie, csrf_cookie):
    """Create a requests session with LeetCode auth cookies."""
    s = requests.Session()
    s.cookies.set("LEETCODE_SESSION", session_cookie, domain=".leetcode.com")
    s.cookies.set("csrftoken", csrf_cookie, domain=".leetcode.com")
    s.headers.update(
        {
            "Content-Type": "application/json",
            "Referer": "https://leetcode.com/",
            "x-csrftoken": csrf_cookie,
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36",
        }
    )
    return s


def get_last_sync_timestamp():
    """Read the last sync timestamp (epoch seconds). Returns 0 if never synced."""
    if LAST_SYNC_FILE.exists():
        try:
            return int(LAST_SYNC_FILE.read_text().strip())
        except (ValueError, OSError):
            return 0
    return 0


def save_last_sync_timestamp(ts):
    """Persist the last sync timestamp."""
    LAST_SYNC_FILE.write_text(str(ts))


def send_windows_notification(title, message):
    """Send a Windows toast notification (best-effort)."""
    try:
        from ctypes import windll
        # Use PowerShell for a toast notification
        ps_script = f"""
        [Windows.UI.Notifications.ToastNotificationManager, Windows.UI.Notifications, ContentType = WindowsRuntime] > $null
        $template = [Windows.UI.Notifications.ToastNotificationManager]::GetTemplateContent([Windows.UI.Notifications.ToastTemplateType]::ToastText02)
        $textNodes = $template.GetElementsByTagName('text')
        $textNodes.Item(0).AppendChild($template.CreateTextNode('{title}')) > $null
        $textNodes.Item(1).AppendChild($template.CreateTextNode('{message}')) > $null
        $toast = [Windows.UI.Notifications.ToastNotification]::new($template)
        [Windows.UI.Notifications.ToastNotificationManager]::CreateToastNotifier('LeetCode Sync').Show($toast)
        """
        subprocess.run(
            ["powershell", "-Command", ps_script],
            capture_output=True,
            timeout=10,
        )
    except Exception:
        pass  # Notifications are best-effort


# ---------------------------------------------------------------------------
# LeetCode API
# ---------------------------------------------------------------------------


def fetch_recent_submissions(session, limit=20):
    """Fetch recent accepted submissions using the public GraphQL query."""
    query = """
    query recentAcSubmissions($username: String!, $limit: Int!) {
        recentAcSubmissionList(username: $username, limit: $limit) {
            id
            title
            titleSlug
            timestamp
            lang
            statusDisplay
        }
    }
    """
    variables = {"username": LEETCODE_USERNAME, "limit": limit}

    try:
        resp = session.post(GRAPHQL_URL, json={"query": query, "variables": variables})
        resp.raise_for_status()
        data = resp.json()

        if "errors" in data:
            log.error("GraphQL errors: %s", data["errors"])
            return None  # Return None to signal possible auth failure

        submissions = data.get("data", {}).get("recentAcSubmissionList")
        if submissions is None:
            log.warning("Session may have expired — submissions returned null")
            return None

        return submissions

    except requests.RequestException as e:
        log.error("Network error fetching submissions: %s", e)
        return None


def fetch_submission_code(session, submission_id):
    """Fetch the actual code for a specific submission."""
    query = """
    query submissionDetails($submissionId: Int!) {
        submissionDetails(submissionId: $submissionId) {
            code
            lang {
                name
                verboseName
            }
            runtime
            memory
            statusDisplay
            timestamp
        }
    }
    """
    variables = {"submissionId": int(submission_id)}

    try:
        resp = session.post(GRAPHQL_URL, json={"query": query, "variables": variables})
        resp.raise_for_status()
        data = resp.json()

        if "errors" in data:
            log.warning(
                "Could not fetch code for submission %s: %s",
                submission_id,
                data["errors"],
            )
            return None

        return data.get("data", {}).get("submissionDetails")

    except requests.RequestException as e:
        log.warning("Network error fetching submission %s: %s", submission_id, e)
        return None


# ---------------------------------------------------------------------------
# Git Operations
# ---------------------------------------------------------------------------


def git_run(*args):
    """Run a git command in the repo directory."""
    result = subprocess.run(
        ["git", *args],
        cwd=GITHUB_REPO_PATH,
        capture_output=True,
        text=True,
    )
    if result.returncode != 0 and "nothing to commit" not in result.stderr:
        log.warning("git %s: %s", " ".join(args), result.stderr.strip())
    return result


def save_and_commit_solution(title_slug, lang_slug, code, timestamp_epoch):
    """Save a solution file and commit it."""
    repo = Path(GITHUB_REPO_PATH)
    dest_folder = repo / "leetcode-solutions" / title_slug

    # Determine file extension
    ext = LANG_EXTENSIONS.get(lang_slug.lower(), ".txt")
    solution_file = dest_folder / f"solution{ext}"

    # Skip if file already exists with same content
    if solution_file.exists():
        try:
            existing = solution_file.read_text(encoding="utf-8").strip()
            if existing == code.strip():
                log.info("  ⏭️  Skipping %s (%s) — already up to date", title_slug, lang_slug)
                return False
        except Exception:
            pass

    # Write solution
    dest_folder.mkdir(parents=True, exist_ok=True)
    solution_file.write_text(code, encoding="utf-8")

    # Create a README for the problem folder
    readme_file = dest_folder / "README.md"
    if not readme_file.exists():
        problem_url = f"https://leetcode.com/problems/{title_slug}/"
        dt = datetime.fromtimestamp(int(timestamp_epoch), tz=timezone.utc)
        readme_content = (
            f"# {title_slug.replace('-', ' ').title()}\n\n"
            f"- **LeetCode**: [{title_slug}]({problem_url})\n"
            f"- **Language**: {lang_slug}\n"
            f"- **First Solved**: {dt.strftime('%Y-%m-%d')}\n"
        )
        readme_file.write_text(readme_content, encoding="utf-8")

    # Stage and commit
    git_run("add", str(dest_folder.relative_to(repo)))

    dt = datetime.fromtimestamp(int(timestamp_epoch), tz=timezone.utc)
    commit_msg = f"LeetCode Sync: {title_slug} ({lang_slug}) — {dt.strftime('%Y-%m-%d')}"

    # Set commit date to the submission time for accurate GitHub graph
    env = os.environ.copy()
    env["GIT_AUTHOR_DATE"] = dt.isoformat()
    env["GIT_COMMITTER_DATE"] = dt.isoformat()

    result = subprocess.run(
        ["git", "commit", "-m", commit_msg],
        cwd=GITHUB_REPO_PATH,
        capture_output=True,
        text=True,
        env=env,
    )

    if result.returncode == 0:
        log.info("  ✅ Committed: %s (%s)", title_slug, lang_slug)
        return True
    elif "nothing to commit" in result.stdout or "nothing to commit" in result.stderr:
        log.info("  ⏭️  No changes for %s", title_slug)
        return False
    else:
        log.warning("  ⚠️  Commit issue: %s", result.stderr.strip())
        return False


# ---------------------------------------------------------------------------
# Main Sync Logic
# ---------------------------------------------------------------------------


def sync():
    """Main sync entrypoint."""
    log.info("=" * 60)
    log.info("🟢 LeetCode Sync started at %s", datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
    log.info("=" * 60)

    validate_config()

    # Get cookies (auto-extract from Chrome → cached → manual .env)
    session_cookie, csrf_cookie = get_cookies()
    if not session_cookie or not csrf_cookie:
        send_windows_notification(
            "LeetCode Sync Failed",
            "Could not get cookies. Close Chrome and re-run, or run refresh-cookies.ps1",
        )
        sys.exit(1)

    session = get_session(session_cookie, csrf_cookie)
    last_sync = get_last_sync_timestamp()

    if last_sync > 0:
        dt = datetime.fromtimestamp(last_sync, tz=timezone.utc)
        log.info("Last sync: %s", dt.strftime("%Y-%m-%d %H:%M:%S UTC"))
    else:
        log.info("First sync — fetching recent submissions")

    # Pull latest changes first
    log.info("Pulling latest from remote...")
    git_run("pull", "--rebase", "origin", "main")

    # Fetch recent submissions
    log.info("Fetching submissions from LeetCode...")
    submissions = fetch_recent_submissions(session, limit=20)

    # If submissions failed, cookies may be expired → try refreshing
    if submissions is None:
        log.warning("Cookies may have expired. Attempting auto-refresh from Chrome...")
        # Clear cache and re-extract
        if COOKIE_CACHE_FILE.exists():
            COOKIE_CACHE_FILE.unlink()

        session_cookie, csrf_cookie = extract_cookies_from_chrome()
        if session_cookie and csrf_cookie:
            session = get_session(session_cookie, csrf_cookie)
            submissions = fetch_recent_submissions(session, limit=20)

        if submissions is None:
            log.error("❌ Could not fetch submissions even after cookie refresh.")
            send_windows_notification(
                "LeetCode Sync Failed",
                "Session expired. Close Chrome and re-run sync.py",
            )
            return

    if not submissions:
        log.info("No submissions found. Exiting.")
        return

    # Filter to only new submissions since last sync
    new_submissions = [s for s in submissions if int(s["timestamp"]) > last_sync]

    if not new_submissions:
        log.info("✅ Everything is already synced! No new submissions.")
        return

    log.info("Found %d new submission(s) to sync", len(new_submissions))

    # Process each submission (oldest first for correct commit order)
    new_submissions.sort(key=lambda s: int(s["timestamp"]))
    committed_count = 0
    latest_ts = last_sync

    for sub in new_submissions:
        title_slug = sub["titleSlug"]
        lang = sub.get("lang", "unknown")
        ts = int(sub["timestamp"])

        log.info("Processing: %s (%s)", sub["title"], lang)

        # Fetch the actual code
        details = fetch_submission_code(session, sub["id"])

        if details and details.get("code"):
            code = details["code"]
            # The lang from details might be an object, handle both cases
            if isinstance(details.get("lang"), dict):
                lang_slug = details["lang"].get("name", lang).lower()
            else:
                lang_slug = lang.lower()

            if save_and_commit_solution(title_slug, lang_slug, code, ts):
                committed_count += 1
        else:
            log.warning("  ⚠️  Could not fetch code for %s — skipping", title_slug)

        latest_ts = max(latest_ts, ts)

        # Rate limiting — be respectful to LeetCode's servers
        time.sleep(1.5)

    # Push all commits
    if committed_count > 0:
        log.info("Pushing %d commit(s) to remote...", committed_count)
        push_result = git_run("push", "origin", "main")
        if push_result.returncode == 0:
            log.info("✅ Push successful!")
            send_windows_notification(
                "LeetCode Sync ✅",
                f"Synced {committed_count} new solution(s) to GitHub!",
            )
        else:
            # Try 'master' branch if 'main' fails
            push_result = git_run("push", "origin", "master")
            if push_result.returncode == 0:
                log.info("✅ Push successful (master branch)!")
            else:
                log.error("❌ Push failed: %s", push_result.stderr.strip())

    # Save sync timestamp
    save_last_sync_timestamp(latest_ts)

    log.info("=" * 60)
    log.info("🏁 Sync complete! %d new solution(s) committed.", committed_count)
    log.info("=" * 60)


if __name__ == "__main__":
    try:
        sync()
    except KeyboardInterrupt:
        log.info("Sync cancelled by user.")
    except Exception as e:
        log.exception("Unexpected error: %s", e)
        sys.exit(1)
