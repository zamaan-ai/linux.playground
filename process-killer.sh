#!/bin/bash
echo "=== TOP CPU PROCESSES ==="
ps aux --sort=-%cpu | head -11 | tail -6 | awk '{print $2 "\t" $11 "\t" $3"%"}'
echo ""
read -p "Kill high CPU process? (y/N): " ans
if [ "$ans" = "y" ]; then
  read -p "Enter PID: " pid
  kill -9 $pid && echo "✅ Killed $pid"
fi
