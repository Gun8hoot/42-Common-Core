#!/bin/bash

CERTIFICATE_INFO='/C=FR/ST=Normandie/L=LeHavre/CN=nclavel.42.fr'

SRCS_PATH="./srcs"
SECRET_PATH="./secret"
VOLUME_PATH="$HOME/data"

printf """\e[0;34m    ____      _ __         __
   /  _/___  (_) /_  _____/ /_
   / // __ \/ / __/ / ___/ __ \\
 _/ // / / / / /__ (__  ) / / /
/___/_/ /_/_/\__(_)____/_/ /_/
    --- Inception Initialization Script ---\e[0m\n"""

# -- CHECK IF $HOME IS SET --
if [ "$HOME" == "" ]; then
	printf '\x1b[31m[!] $HOME is not set\x1b[0m\n'
	exit 1
fi


# -- CHECK IF THE .ENV EXIST --
if [ ! -f $SRCS_PATH/.env ]; then
	printf "\x1b[31m[!] .env doesnt exist, using template.env file instead.\x1b[0m\n" 1>&2
	cp $SRCS_PATH/template.env $SRCS_PATH/.env
	if [ $? -ne 0 ]; then
		exit 1
	fi
fi


# -- INITIALIZE VOLUMES DIRECTORY --
if	[ ! -d "$VOLUME_PATH/mariadb" ] \
		|| [ ! -d "$VOLUME_PATH/wordpress" ] \
		|| [ ! -d "$VOLUME_PATH/adminer" ] \
		|| [ ! -d "$VOLUME_PATH/logs" ]; then
	printf "\x1b[33m[!] Initialize volumes\n\x1b[0m" 1>&2
	mkdir -p $VOLUME_PATH/{mariadb,wordpress,adminer,logs}
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to create volumes directory\n\x1b[0m" 1>&2
		exit 1
	else
		printf "\x1b[32m[+] Volume directory created in $VOLUME_PATH\n\x1b[0m" 1>&2
	fi
fi
# -- INITIALIZE ADMINER --
if [ ! -f "$VOLUME_PATH/adminer/index.php" ]; then
	printf "\x1b[33m[!] Initialize adminer\n\x1b[0m" 1>&2
	mkdir -p $VOLUME_PATH/adminer/
	wget --quiet https://github.com/vrana/adminer/releases/download/v6.0.1/adminer-6.0.1.php -O $VOLUME_PATH/adminer/index.php
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to download adminer index file in $VOLUME_PATH/adminer\n\x1b[0m" 1>&2
		exit 1
	else
		printf "\x1b[32m[+] Downloaded adminer index file in $VOLUME_PATH/adminer\n\x1b[0m" 1>&2
	fi
fi
# -- INITIALIZE WORDPRESS --
if [ ! -d "$VOLUME_PATH/wordpress" ] || [ $(ls $VOLUME_PATH/wordpress/ | wc -w) -eq 0 ]; then
	printf "\x1b[33m[!] Initialize wordpress\n\x1b[0m" 1>&2
	mkdir -p $VOLUME_PATH/wordpress
	wget --quiet https://wordpress.org/latest.tar.gz -O /tmp/latest.tar.gz
	tar -xf /tmp/latest.tar.gz -C $VOLUME_PATH/
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to download wordpress content\n\x1b[0m" 1>&2
		exit 1
	else
		printf "\x1b[32m[+] Downloaded wordpress in $VOLUME_PATH/wordpress\n\x1b[0m" 1>&2
	fi
	rm -f /tmp/latest.tar.gz
fi
# -- DOWNLOADING THE REDIS PLUGIN FOR WORDPRESS --
if [ ! -f $SRCS_PATH/wordpress/redis-plugin.zip ]; then
	wget https://downloads.wordpress.org/plugin/redis-cache.2.8.0.zip -O $SRCS_PATH/wordpress/redis-plugin.zip
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to download \"Redis Object Cache Plugin\"\n\x1b[0m" 1>&2
		exit 1
	fi
	printf "\x1b[32m[!] Download Redis Object Cache Plugin for wordpress complete\n\x1b[0m" 1>&2
fi


# -- INITIALIZE SECRET DIRECTORY --
if [ ! -d "$SECRET_PATH" ]; then
	printf "\x1b[33m[!] Initializing secret directory\n\x1b[0m" 1>&2
	mkdir -p $SECRET_PATH
fi
# -- INITIALIZE SELF-SIGNED CERTIFICATE --
if [ ! -d $SECRET_PATH/cert ] || [ $(ls $SECRET_PATH/cert | wc -w) -ne 4 ]; then
	printf "\x1b[33m[!] Generating new certificates\n\x1b[0m" 1>&2
	mkdir -p $SECRET_PATH/cert
	openssl req -subj $CERTIFICATE_INFO -x509 -nodes -days 365 -new -newkey rsa:2048 -keyout $SECRET_PATH/cert/nginx.key -out $SECRET_PATH/cert/nginx.crt -quiet
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to generate SSL certificate for nginx\n\x1b[0m" 1>&2
		exit 1
	fi
	openssl req -subj $CERTIFICATE_INFO -x509 -nodes -days 365 -new -newkey rsa:2048 -keyout $SECRET_PATH/cert/vsftpd.key -out $SECRET_PATH/cert/vsftpd.crt -quiet
	if [ $? -ne 0 ]; then
		printf "\x1b[31m[!] Failed to generate SSL certificate for vsftpd\n\x1b[0m" 1>&2
		exit 1
	fi
	printf "\x1b[32m[+] New certificate generated in ./$SECRET_PATH/cert\n\x1b[0m" 1>&2
fi


printf "\n\x1b[32m[!] Initialization complete !\n\x1b[0m" 1>&2
