#!/bin/bash
echo "=== NETWORK TOOLS (Day 6) ==="

echo ""
echo "--- Your IP addresses ---"
ip addr show 2>/dev/null || ifconfig 2>/dev/null

echo ""
echo "--- Listening ports (TCP/UDP) ---"
netstat -tuln 2>/dev/null | head -15

echo ""
echo "--- Ping test ---"
read -p "Enter host/IP to ping (default: google.com): " host
host=${host:-google.com}
ping -c 4 "$host"
