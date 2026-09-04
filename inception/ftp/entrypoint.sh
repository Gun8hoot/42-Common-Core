#!/bin/env sh

chown -R root:ftp_gr /srv/ftp
chmod -R 777 /srv/ftp/

vsftpd /etc/vsftpd.conf
