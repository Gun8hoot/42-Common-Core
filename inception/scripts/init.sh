#!/bin/bash

CERTIFICATE_INFO='/C=FR/ST=Normandie/L=LeHavre/CN=nclavel.42.fr'

printf """\e[0;34m
    ____      _ __         __
   /  _/___  (_) /_  _____/ /_
   / // __ \/ / __/ / ___/ __ \\
 _/ // / / / / /__ (__  ) / / /
/___/_/ /_/_/\__(_)____/_/ /_/
    --- Initialization script ---\e[0m\n"""

# -- CHECK IF THE .ENV EXIST --
if [ ! -f $PWD/.env ]; then
	printf "\x1b[31m[!] Missing .env file\n\x1b[0m" 1>&2
	exit 1
fi

# -- INITIALIZE ADMINER --
if [ ! -f $PWD/adminer/frontend/index.php ]; then
	printf "\x1b[33m[!] Initialize adminer\n\x1b[0m" 1>&2
	mkdir -p $PWD/adminer/frontend
	wget --quiet https://github.com/vrana/adminer/releases/download/v6.0.1/adminer-6.0.1-mysql-en.php -O $PWD/adminer/frontend/index.php
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to download adminer php file\n\x1b[0m" 1>&2
		exit 1
	else
		printf "\x1b[32m[+] Downloaded adminer php file\n\x1b[0m" 1>&2
	fi

fi
# -- INITIALIZE VOLUMES DIRECTORY --
if [ ! -d "$HOME/data/ftp" ] || [ ! -d "$HOME/data/mariadb" ] || [ ! -d "$HOME/data/wordpress" ]; then
	printf "\x1b[33m[!] Initialize volumes\n\x1b[0m" 1>&2
	mkdir -p $HOME/data/{ftp,mariadb,wordpress}
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to create volumes directory\n\x1b[0m" 1>&2
		exit 1
	else
		printf "\x1b[32m[+] Volume directory created in $HOME/data\n\x1b[0m" 1>&2
	fi
fi
# -- INITIALIZE WORDPRESS --
if [ ! -d "$HOME/data/wordpress" ] || [ $(ls $HOME/data/wordpress/ | wc -w) -eq 0 ]; then
	printf "\x1b[33m[!] Initialize wordpress\n\x1b[0m" 1>&2
	mkdir -p $HOME/data/wordpress
	wget --quiet https://wordpress.org/latest.tar.gz -O $HOME/data/wordpress/latest.tar.gz
	tar -xf $HOME/data/wordpress/latest.tar.gz -C $HOME/data/
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to download wordpress\n\x1b[0m" 1>&2
		exit 1
	else
		printf "\x1b[32m[+] Downloaded wordpress in $HOME/data/wordpress\n\x1b[0m" 1>&2
	fi
	rm -f $HOME/data/wordpress/latest.tar.gz
fi
# -- INITIALIZE SELF-SIGNED CERTIFICATE --
if [ ! -d $PWD/.cert ] || [ $(ls $PWD/.cert | wc -w) -ne 4 ]; then
	printf "\x1b[33m[!] Creating new certificate\n\x1b[0m" 1>&2
	mkdir -p $PWD/.cert
	openssl req -subj $CERTIFICATE_INFO -x509 -nodes -days 365 -new -newkey rsa:2048 -keyout $PWD/.cert/nginx.key -out $PWD/.cert/nginx.crt -quiet
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to generate certificate for nginx\n\x1b[0m" 1>&2
		exit 1
	fi
	openssl req -subj $CERTIFICATE_INFO -x509 -nodes -days 365 -new -newkey rsa:2048 -keyout $PWD/.cert/vsftpd.key -out $PWD/.cert/vsftpd.crt -quiet
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to generate certificate for vsftpd\n\x1b[0m" 1>&2
		exit 1
	fi
	printf "\x1b[32m[+] New certificate generated in $PWD/.cert\n\x1b[0m" 1>&2
fi
# -- INITIALIZE LOGGIN --
if [ ! -d $PWD/logs ]; then
	mkdir -p $PWD/logs
	touch $PWD/logs/mariadb.log
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to create the log directory\n\x1b[0m" 1>&2
		exit 1
	fi
	printf "\x1b[32m[+] Create a loggin directory in $PWD/logs\n\x1b[0m" 1>&2
fi
printf "\x1b[32m[+] Initialization complete !\n\x1b[0m" 1>&2
