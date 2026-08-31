#!/bin/env sh

pkill vsftpd

chown -R root:ftp_gr /srv/ftp
chmod 777 /srv/ftp/

vsftpd /etc/vsftpd.conf
