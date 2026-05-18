#!/bin/bash


mkdir -p /srv/www
chown www-data: /srv/www
tar zx -C /srv/www /tmp/latest.zip

rm -f /tmp/latest.zip
