<#
.SYNOPSIS
    🔄 LeetCode Cookie Refresh Helper
    Quickly update your LeetCode session cookies in .env (and optionally GitHub Secrets).

.DESCRIPTION
    LeetCode session cookies expire every ~1-2 weeks.
    This script makes refreshing them a 30-second task:
    1. Opens LeetCode in your browser
    2. Asks you to paste the two cookie values
    3. Updates your local .env file
    4. Optionally updates GitHub Secrets (if gh CLI is installed)

.NOTES
    Run this when sync.py starts failing with "session expired" errors.
#>

$ErrorActionPreference = "Stop"
$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$EnvFile = Join-Path $ScriptDir ".env"

# ── Banner ──────────────────────────────────────────────────────────────────
Write-Host ""
Write-Host "  ╔══════════════════════════════════════════════╗" -ForegroundColor Cyan
Write-Host "  ║   🔄 LeetCode Cookie Refresh                ║" -ForegroundColor Cyan
Write-Host "  ╚══════════════════════════════════════════════╝" -ForegroundColor Cyan
Write-Host ""

# ── Step 1: Open LeetCode ──────────────────────────────────────────────────
Write-Host "Step 1: Opening LeetCode in your browser..." -ForegroundColor Yellow
Write-Host "        → Log in if needed" -ForegroundColor Gray
Write-Host "        → Press F12 → Application tab → Cookies → https://leetcode.com" -ForegroundColor Gray
Write-Host ""
Start-Process "https://leetcode.com"
Start-Sleep -Seconds 2

# ── Step 2: Get cookies from user ──────────────────────────────────────────
Write-Host "Step 2: Paste cookie values from your browser DevTools" -ForegroundColor Yellow
Write-Host ""

$session = Read-Host "   Paste LEETCODE_SESSION value"
if ([string]::IsNullOrWhiteSpace($session)) {
    Write-Host "   ❌ LEETCODE_SESSION cannot be empty. Aborting." -ForegroundColor Red
    exit 1
}

$csrf = Read-Host "   Paste csrftoken value"
if ([string]::IsNullOrWhiteSpace($csrf)) {
    Write-Host "   ❌ csrftoken cannot be empty. Aborting." -ForegroundColor Red
    exit 1
}

# ── Step 3: Update .env file ──────────────────────────────────────────────
Write-Host ""
Write-Host "Step 3: Updating .env file..." -ForegroundColor Yellow

if (-Not (Test-Path $EnvFile)) {
    # Create .env from .env.example if it doesn't exist
    $exampleFile = Join-Path $ScriptDir ".env.example"
    if (Test-Path $exampleFile) {
        Copy-Item $exampleFile $EnvFile
        Write-Host "   Created .env from .env.example" -ForegroundColor Gray
    } else {
        # Create a minimal .env
        @"
LEETCODE_SESSION=
LEETCODE_CSRF_TOKEN=
LEETCODE_USERNAME=
GITHUB_REPO_PATH=
"@ | Set-Content $EnvFile -Encoding UTF8
    }
}

# Read current .env content
$envContent = Get-Content $EnvFile -Raw

# Replace or add LEETCODE_SESSION
if ($envContent -match "(?m)^LEETCODE_SESSION=.*$") {
    $envContent = $envContent -replace "(?m)^LEETCODE_SESSION=.*$", "LEETCODE_SESSION=$session"
} else {
    $envContent += "`nLEETCODE_SESSION=$session"
}

# Replace or add LEETCODE_CSRF_TOKEN
if ($envContent -match "(?m)^LEETCODE_CSRF_TOKEN=.*$") {
    $envContent = $envContent -replace "(?m)^LEETCODE_CSRF_TOKEN=.*$", "LEETCODE_CSRF_TOKEN=$csrf"
} else {
    $envContent += "`nLEETCODE_CSRF_TOKEN=$csrf"
}

$envContent | Set-Content $EnvFile -Encoding UTF8 -NoNewline
Write-Host "   ✅ .env updated successfully!" -ForegroundColor Green

# ── Step 4: Optionally update GitHub Secrets ──────────────────────────────
Write-Host ""
$ghInstalled = Get-Command gh -ErrorAction SilentlyContinue

if ($ghInstalled) {
    Write-Host "Step 4: GitHub CLI detected. Update GitHub Secrets too?" -ForegroundColor Yellow
    $updateGH = Read-Host "   Update GitHub Secrets? (y/N)"

    if ($updateGH -eq "y" -or $updateGH -eq "Y") {
        $repoName = Read-Host "   Enter GitHub repo (e.g., yourusername/leetcode-solutions)"

        try {
            Write-Host "   Updating LEETCODE_SESSION secret..." -ForegroundColor Gray
            $session | gh secret set LEETCODE_SESSION --repo $repoName

            Write-Host "   Updating LEETCODE_CSRF_TOKEN secret..." -ForegroundColor Gray
            $csrf | gh secret set LEETCODE_CSRF_TOKEN --repo $repoName

            Write-Host "   ✅ GitHub Secrets updated!" -ForegroundColor Green
        } catch {
            Write-Host "   ⚠️  Failed to update GitHub Secrets: $_" -ForegroundColor Red
            Write-Host "   You can update them manually at: https://github.com/$repoName/settings/secrets/actions" -ForegroundColor Gray
        }
    }
} else {
    Write-Host "Step 4: GitHub CLI (gh) not installed — skipping GitHub Secrets update." -ForegroundColor Gray
    Write-Host "        Install it from https://cli.github.com if you want auto-updates." -ForegroundColor Gray
    Write-Host "        Or update manually in your repo → Settings → Secrets → Actions." -ForegroundColor Gray
}

# ── Done ──────────────────────────────────────────────────────────────────
Write-Host ""
Write-Host "  ╔══════════════════════════════════════════════╗" -ForegroundColor Green
Write-Host "  ║   ✅ Cookies refreshed successfully!         ║" -ForegroundColor Green
Write-Host "  ║                                              ║" -ForegroundColor Green
Write-Host "  ║   Test it: python sync.py                    ║" -ForegroundColor Green
Write-Host "  ╚══════════════════════════════════════════════╝" -ForegroundColor Green
Write-Host ""
