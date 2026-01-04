#!/bin/bash
LOG=${1:-/var/log/system.log}
echo "=== LOG ANALYZER ==="
echo "ERRORS: $(grep -ci error "$LOG")"
echo "WARNINGS: $(grep -ci warn "$LOG")"
echo "Recent errors:"
grep -i error "$LOG" | tail -3
