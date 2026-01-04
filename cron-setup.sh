#!/bin/bash
echo "=== HENNGE CRON JOBS ==="

# Hourly system monitor
echo "* * * * * cd ~/linux.playground && ./system-monitor.sh >> ~/linux.playground/monitor.log" | crontab -

# Daily backup (2AM)
echo "0 2 * * * cd ~/linux.playground && ./backup-repo.sh >> ~/linux.playground/backup.log" | crontab -

crontab -l
echo "✅ Scheduled!"
