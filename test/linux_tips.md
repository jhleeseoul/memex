# Linux Tips

## File Management
- **List files**: Use `ls` to list files and directories.
- **Navigate directories**: Use `cd <directory>` to change the current directory.
- **Copy files**: Use `cp <source> <destination>` to copy files or directories.
- **Move files**: Use `mv <source> <destination>` to move or rename files.
- **Remove files**: Use `rm <file>` to delete files. Use `rm -r <directory>` to delete directories.

## Searching
- **Search inside files**: Use `grep <pattern> <file>` to find specific text within files.
- **Find files**: Use `find <path> -name <filename>` to locate files by name.
- **Search recursively**: Use `grep -r <pattern> <directory>` to search for a pattern in all files within a directory.

## Process Monitoring
- **Monitor processes**: Use `top` or `htop` to view and manage running processes.
- **Kill a process**: Use `kill <PID>` to terminate a process by its Process ID.
- **View process tree**: Use `pstree` to display processes in a tree format.

## Permissions
- **Make a file executable**: Use `chmod +x <file>` to grant executable permissions.
- **Change ownership**: Use `chown <user>:<group> <file>` to change the owner and group of a file.
- **Modify permissions**: Use `chmod <permissions> <file>` to set specific permissions (e.g., `chmod 755 <file>`).

## Networking
- **Check network configuration**: Use `ifconfig` or `ip addr` to view network settings.
- **Test connectivity**: Use `ping <host>` to check if a host is reachable.
- **Download files**: Use `wget <url>` or `curl -O <url>` to download files from the internet.

## Disk Usage
- **Check disk usage**: Use `df -h` to view disk space usage in a human-readable format.
- **Check directory size**: Use `du -sh <directory>` to display the size of a directory.

## System Information
- **View system info**: Use `uname -a` to display system information.
- **Check memory usage**: Use `free -h` to view memory usage in a human-readable format.
- **Check uptime**: Use `uptime` to see how long the system has been running.


