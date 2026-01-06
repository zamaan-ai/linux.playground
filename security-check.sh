#!/bin/bash
echo "=== SECURITY SCAN (Day 8) ==="
echo "Failed logins:"
lastb 2>/dev/null | tail -3 || echo "Install: sudo apt install login-utils"

echo ""
echo "Open ports:"
lsof -i -P -n | grep LISTEN | wc -l 2>/dev/null || netstat -tuln | grep LISTEN | wc -l

echo ""
echo "Sudo users:"
dscl . -list /Users | grep -E "(admin|wheel|sudo)" | cut -d: -f4 2>/dev/null || echo "admin users"
