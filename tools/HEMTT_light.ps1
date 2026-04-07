[CmdletBinding()]
param(
    [string] $RepoRoot = ""
)

$ErrorActionPreference = "Stop"

if (-not $RepoRoot) {
    $RepoRoot = Split-Path -Parent $PSScriptRoot
}

$RepoRoot = (Resolve-Path -LiteralPath $RepoRoot).Path
$projectToml = Join-Path $RepoRoot ".hemtt\project.toml"
if (-not (Test-Path -LiteralPath $projectToml)) {
    throw "Not a HEMTT repo root (missing .hemtt\project.toml): $RepoRoot"
}

$hemtt = Get-Command hemtt -ErrorAction SilentlyContinue
if (-not $hemtt) {
    throw "hemtt not found on PATH. Install HEMTT or add it to PATH, then retry."
}

Push-Location $RepoRoot
try {
    & hemtt check --error-on-all
    exit $LASTEXITCODE
}
finally {
    Pop-Location
}
