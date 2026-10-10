# Changelog

All notable changes to this package are documented here.

## 2.0.1 (2026-09-22)

### Added

- Root bilingual README (`README.md`, `README_cn.md`) for TopsBot release documentation compliance.
- Keep a Changelog entry for repository version `2.0.1`.
- GitLab → GitHub release sync scaffolding (`.gitlab-ci.yml`, `release.yaml`, `ci/release-sync.sh`) and root `LICENSE` (Apache-2.0).

### Changed

- Keep root bilingual README short and limited to vendor setup notes plus in-tree paths/commands (no OS/ROS distro assumptions).
- Replace vendor root `readMe.txt` with `README.md` / `README_cn.md`.
- Align public docs with vendor package version `2.0.1` (version itself unchanged).

### Removed

- Root `readMe.txt` (superseded by README).
- Speculative OS/ROS version claims from earlier draft README.
