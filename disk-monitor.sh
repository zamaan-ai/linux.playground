#!/bin/bash
echo "=== DISK MONITOR (Day 7) ==="
df -h | grep -E '/$' | while read fs size used avail perc mount; do
  perc=${perc%\%}
  if [ $perc -gt 80 ]; then
    echo "🚨 $fs $perc% FULL ($used/$size)"
  else
    echo "✅ $fs $perc% ($used/$size)"
  fi
done
