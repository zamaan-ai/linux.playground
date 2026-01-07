#!/bin/bash
# Day 9: Firewall + Port Security (HENNGE Challenge)
echo "🔥 FIREWALL + PORT SECURITY SCAN (Day 9)"

echo ""
echo "1. Firewall Status:"
if command -v pfctl >/dev/null; then
    sudo pfctl -s info 2>/dev/null | head -3 || echo "macOS: System Settings > Network > Firewall"
else
    echo "No pf firewall (Linux?): sudo ufw status"
fi

echo ""
echo "2. Active Connections:"
lsof -iTCP -sTCP:ESTABLISHED -P -n 2>/dev/null | wc -l | xargs echo "TCP connections: "

echo ""
echo "3. Risky Ports Scan (Telnet/SunRPC/Samba):"
RISKY_PORTS="23 111 139 445"
for port in $RISKY_PORTS; do
    if lsof -i :$port >/dev/null 2>&1; then
        echo "❌ DANGER: Port $port OPEN"
    fi
done || echo "✅ No risky ports detected"

echo ""
echo "4. Recent Failed Logins:"
sudo lastb 2>/dev/null | tail -3 || echo "No auth.log access"

echo "🔒 Scan complete"
