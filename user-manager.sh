#!/bin/bash
echo "=== USER MANAGER (Day 8) ==="

echo "Active users:"
w | head -6 | awk '{print $1 " " $5 " " $NF}'

echo ""
echo "Logged sessions:"
who | wc -l

echo ""
read -p "Disk usage by user? (y/N): " check
if [ "$check" = "y" ]; then
  echo "Top users disk:"
  du -sh /Users/* 2>/dev/null | sort -hr | head -3
fi
