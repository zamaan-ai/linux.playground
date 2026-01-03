#!/bin/bash
TIMESTAMP=$(date +%Y%m%d_%H%M%S)
BACKUP_DIR=~/backups/linux.playground_$TIMESTAMP
mkdir -p $BACKUP_DIR

echo "=== HENNGE BACKUP [$(date)] ==="
git status --short > $BACKUP_DIR/git-status.txt
git log --oneline -5 > $BACKUP_DIR/git-log.txt
tar -czf $BACKUP_DIR/repo.tar.gz .
./system-monitor.sh > $BACKUP_DIR/health.txt

echo "✅ Backup saved: $BACKUP_DIR"
ls -lh $BACKUP_DIR
