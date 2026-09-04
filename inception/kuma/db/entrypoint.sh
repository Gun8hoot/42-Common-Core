#!/bin/sh

DATABASE_LOCATION=/var/lib/mysql

function ping_database
{
	TO=0
	printf "Attempting to ping ...\n"
	# Ping since the database is down
	if [ "$1" == "down" ]; then
		until ! mariadb-admin ping  -u root -p"$KUMA_ROOT_PASSWORD" --silent ; do
			if [ $TO -eq 15 ]; then # Timeout after 15s
				printf "\x1b[33m[!] FATAL ERROR : DATABASE TIMEOUT\x1b[0m\n"
				printf "$(date "+%Y-%m-%d %H:%M:%S") 0 [ERROR] Fatal error: Database initialization timeout\n" >> /var/logs/mariadb/mariadb.log
				exit 1
			fi
			TO=$(($TO+1))
			sleep 1
		done
	# Ping since the database is up
	else
		until mariadb-admin ping  -u root -p"$KUMA_ROOT_PASSWORD" --silent ; do
			if [ $TO -eq 15 ]; then # Timeout after 15s
				printf "\x1b[33m[!] FATAL ERROR : DATABASE TIMEOUT\x1b[0m\n"
				printf "$(date "+%Y-%m-%d %H:%M:%S") 0 [ERROR] Fatal error: Database initialization timeout\n" >> /var/logs/mariadb/mariadb.log
				exit 1
			fi
			TO=$(($TO+1))
			sleep 1
		done
	fi
}

function check_file_exist()
{
	local fileToFound=$1
	for file in *; do
		if [[ "$file" == "$fileToFound" ]]; then
			return 1
		fi
	done
	return 0
}

function main
{
	printf "--- START ---\n"
	# --- INITIALIZED MARIADB ---
	check_file_exist "$DATABASE_LOCATION/mysql.user"
	if [ $? -eq 1 ]; then
		mariadb-upgrade --user=mysql --datadir=$DATABASE_LOCATION > /dev/null
	else
		mariadb-install-db --user=mysql --datadir=$DATABASE_LOCATION >/dev/null
	fi
	if [ $? -eq 1 ]; then
		printf "A probleme occurend during the initialization of the database\n"
		exit 1
	fi
	# --- STARTING MARIADB DAEMON ---
	mariadbd --user=root --datadir="$DATABASE_LOCATION" &
	ping_database

	# --- CONFIGURING THE DATABASE ---
	cat > init.sql << EOF
	CREATE DATABASE IF NOT EXISTS kuma DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
	CREATE USER IF NOT EXISTS 'root'@'localhost' IDENTIFIED BY '$KUMA_ROOT_PASSWORD';
	CREATE USER IF NOT EXISTS '$KUMA_USER'@'172.%.%.%' IDENTIFIED BY '$KUMA_PASSWD';
	GRANT ALL PRIVILEGES ON kuma.* TO '$KUMA_USER'@'172.%.%.%';
	ALTER USER IF EXISTS 'root'@'localhost' IDENTIFIED BY '$KUMA_ROOT_PASSWORD';
	FLUSH PRIVILEGES;
EOF
	mariadb -u root -p"$KUMA_ROOT_PASSWORD" < ./init.sql
	mariadb-admin shutdown -p"$KUMA_ROOT_PASSWORD" -h localhost
	ping_database down
	echo "[+] MariaDB successfully initialized\n" 1>&2
	mariadbd -h mariadb --user=root --console --datadir="$DATABASE_LOCATION"
}

main
