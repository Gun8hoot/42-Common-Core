#!/bin/env sh

set -eu # Stop the script if we command failed

: "${FTP_PASSWORD:?FTP_PASSWORD is not set}"

echo "[+] Changing password for user"
echo "user:${FTP_PASSWORD}" | chpasswd

echo "[+] Changing permission of the ftp directory"
chown -R user:ftp_gr /srv/ftp/
chmod -R 770 /srv/ftp/

echo "[+] Launching vsftpd"
exec vsftpd /etc/vsftpd.conf
