<#
.SYNOPSIS
    📅 Install Windows Scheduled Task for LeetCode Sync
    Registers a task that runs sync.py every 6 hours automatically.

.DESCRIPTION
    One-time setup script. After running this, your LeetCode solutions
    will auto-sync to GitHub every 6 hours whenever your PC is on.

.NOTES
    - Requires Python to be installed and in PATH
    - Run this script once as Administrator (or current user)
    - To uninstall: Unregister-ScheduledTask -TaskName "LeetCodeSync"
#>

$ErrorActionPreference = "Stop"
$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$SyncScript = Join-Path $ScriptDir "sync.py"

# ── Banner ──────────────────────────────────────────────────────────────────
Write-Host ""
Write-Host "  ╔══════════════════════════════════════════════╗" -ForegroundColor Cyan
Write-Host "  ║   📅 LeetCode Sync — Scheduler Setup        ║" -ForegroundColor Cyan
Write-Host "  ╚══════════════════════════════════════════════╝" -ForegroundColor Cyan
Write-Host ""

# ── Check Python ────────────────────────────────────────────────────────────
$pythonCmd = Get-Command python -ErrorAction SilentlyContinue
if (-Not $pythonCmd) {
    $pythonCmd = Get-Command python3 -ErrorAction SilentlyContinue
}
if (-Not $pythonCmd) {
    Write-Host "  ❌ Python not found in PATH. Install Python first." -ForegroundColor Red
    Write-Host "     https://www.python.org/downloads/" -ForegroundColor Gray
    exit 1
}

$pythonPath = $pythonCmd.Source
Write-Host "  ✅ Python found: $pythonPath" -ForegroundColor Green

# ── Check if sync.py exists ────────────────────────────────────────────────
if (-Not (Test-Path $SyncScript)) {
    Write-Host "  ❌ sync.py not found at: $SyncScript" -ForegroundColor Red
    exit 1
}

# ── Check if .env exists ───────────────────────────────────────────────────
$envFile = Join-Path $ScriptDir ".env"
if (-Not (Test-Path $envFile)) {
    Write-Host "  ⚠️  .env file not found. Copy .env.example to .env and configure it first." -ForegroundColor Yellow
    Write-Host "     Run: copy .env.example .env" -ForegroundColor Gray
    exit 1
}

# ── Remove existing task if present ────────────────────────────────────────
$existingTask = Get-ScheduledTask -TaskName "LeetCodeSync" -ErrorAction SilentlyContinue
if ($existingTask) {
    Write-Host "  Removing existing LeetCodeSync task..." -ForegroundColor Yellow
    Unregister-ScheduledTask -TaskName "LeetCodeSync" -Confirm:$false
}

# ── Create the scheduled task ──────────────────────────────────────────────
Write-Host "  Creating scheduled task (every 6 hours)..." -ForegroundColor Yellow

# Action: run python sync.py
$action = New-ScheduledTaskAction `
    -Execute $pythonPath `
    -Argument "`"$SyncScript`"" `
    -WorkingDirectory $ScriptDir

# Trigger: every 6 hours, starting now
$trigger = New-ScheduledTaskTrigger `
    -Once `
    -At (Get-Date) `
    -RepetitionInterval (New-TimeSpan -Hours 6) `
    -RepetitionDuration (New-TimeSpan -Days 365)

# Settings: run even if on battery, don't stop if going to battery,
# start if missed, allow running on demand
$settings = New-ScheduledTaskSettingsSet `
    -AllowStartIfOnBatteries `
    -DontStopIfGoingOnBatteries `
    -StartWhenAvailable `
    -RunOnlyIfNetworkAvailable `
    -MultipleInstances IgnoreNew

# Register the task
try {
    Register-ScheduledTask `
        -TaskName "LeetCodeSync" `
        -Description "Syncs LeetCode solutions to GitHub every 6 hours" `
        -Action $action `
        -Trigger $trigger `
        -Settings $settings `
        -RunLevel Limited

    Write-Host ""
    Write-Host "  ╔══════════════════════════════════════════════╗" -ForegroundColor Green
    Write-Host "  ║   ✅ Scheduled Task installed!               ║" -ForegroundColor Green
    Write-Host "  ║                                              ║" -ForegroundColor Green
    Write-Host "  ║   Task: LeetCodeSync                         ║" -ForegroundColor Green
    Write-Host "  ║   Schedule: Every 6 hours                    ║" -ForegroundColor Green
    Write-Host "  ║   Script: sync.py                            ║" -ForegroundColor Green
    Write-Host "  ╚══════════════════════════════════════════════╝" -ForegroundColor Green
    Write-Host ""
    Write-Host "  To manage:" -ForegroundColor Gray
    Write-Host "    View:      Get-ScheduledTask -TaskName 'LeetCodeSync'" -ForegroundColor Gray
    Write-Host "    Run now:   Start-ScheduledTask -TaskName 'LeetCodeSync'" -ForegroundColor Gray
    Write-Host "    Disable:   Disable-ScheduledTask -TaskName 'LeetCodeSync'" -ForegroundColor Gray
    Write-Host "    Uninstall: Unregister-ScheduledTask -TaskName 'LeetCodeSync'" -ForegroundColor Gray
    Write-Host ""
} catch {
    Write-Host ""
    Write-Host "  ❌ Failed to create scheduled task: $_" -ForegroundColor Red
    Write-Host ""
    Write-Host "  Try running this script as Administrator:" -ForegroundColor Yellow
    Write-Host "    Right-click PowerShell → Run as Administrator" -ForegroundColor Gray
    Write-Host "    Then: .\install-scheduler.ps1" -ForegroundColor Gray
    exit 1
}
