#!/bin/env sh

export FTP_PASSWORD=$(cat /run/secrets/SC_FTP_PWD)

set -eu # Stop the script if we command failed

echo "[+] Changing password for user"
echo "user:$FTP_PASSWORD" | chpasswd

# echo "[+] Changing permission of the ftp directory"
# chown -R nobody:ftp_gr /srv/ftp/
# chmod -R 770 /srv/ftp/

echo "[+] Launching vsftpd"
vsftpd /etc/vsftpd.conf
