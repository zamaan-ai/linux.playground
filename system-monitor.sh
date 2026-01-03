#!/bin/bash
echo "=== SYSTEM MONITOR - HENNGE Prep ==="
echo "Uptime: $(uptime -p)"
echo "Load avg: $(uptime | awk '{print $(NF-2)}')"
echo ""
echo "=== CPU ==="
top -bn1 | grep "Cpu(s)" | sed 's/ *, */ /g' | awk '{print "User: " $2", Sys: " $4", Idle: " $8"%"}'
echo ""
echo "=== MEMORY ==="
free -h | grep Mem | awk '{printf "Used: %s/%s (%.1f%%)\n", $3, $2, $3/$2*100}'
echo ""
echo "=== TOP 5 PROCESSES ==="
ps aux --sort=-%cpu | head -6
