---
name: release
description: Automates the versioning, tagging, and deployment process for the project.
---
# /release

Automates the versioning, tagging, and deployment process for the CatppuccinRGB565 project.

## Description
This skill handles the end-to-end release process: determining the next semantic version, validating code quality and native tests, bumping version metadata in both `library.json` and `library.properties`, committing changes, creating an annotated tag, atomically pushing to the remote repository, and publishing the GitHub release.

## Protocol

1. **Extract and Calculate Version:**
   - Detect current version from metadata or git tags:
     ```bash
     # Check latest tag
     rtk git tag --sort=-v:refname | head -n 1
     # Check current file versions
     grep -E '"version":' library.json
     grep -E '^version=' library.properties
     ```
   - Calculate target semantic version: increment patch version (e.g., `0.1.0` -> `0.1.1`) or use user-specified version (e.g., minor `0.2.0` / major `1.0.0`).

2. **Pre-release Validation:**
   - Run host-native unit tests:
     ```bash
     rtk test pio test -e native
     ```
   - Run example build verification:
     ```bash
     task build
     ```
   - Ensure all tests pass and example builds succeed before modifying version files.

3. **Bump Version in Metadata Files:**
   - Bump version in `library.json` (format without `v` prefix, e.g., `"0.1.1"`):
     ```bash
     jq --arg v "<new_version>" '.version = $v' library.json > library.json.tmp && mv library.json.tmp library.json
     ```
   - Bump version in `library.properties` (format without `v` prefix, e.g., `version=0.1.1`):
     ```bash
     sed -i -E "s/^version=.*/version=<new_version>/" library.properties
     ```
   - **Verify Bump**: Confirm both files reflect the exact same `<new_version>`:
     ```bash
     grep -E '"version":' library.json
     grep -E '^version=' library.properties
     ```
   - Stage and commit the metadata updates:
     ```bash
     rtk git add library.json library.properties
     rtk git commit -m "chore(release): bump version to v<new_version>"
     ```

4. **Verify Git State & Sync:**
   - Ensure clean working tree:
     ```bash
     rtk git status --porcelain
     ```
   - Rebase on remote:
     ```bash
     rtk git pull --rebase origin main
     ```

5. **Tag the Release:**
   - Create an annotated git tag using the `v` prefix (e.g., `v0.1.1`):
     ```bash
     rtk git tag -a v<new_version> -m "Release v<new_version>"
     ```

6. **Atomic Push:**
   - Push branch and tag together atomically:
     ```bash
     rtk git push --atomic origin main v<new_version>
     ```

7. **Generate Release Notes & GitHub Release:**
   - Generate structured release notes following `/release-summary` protocol.
   - Create GitHub release:
     ```bash
     rtk gh release create v<new_version> --title "v<new_version>" --notes-file release_notes.md | cat
     ```
   - Output release URL to the user.

8. **Error Handling:**
   - If any test, build, version bump, or git operation fails, stop immediately, do not tag or push, and report the error to the user.
