#!/bin/sh

bad_username="user usr root admin administrator mariadb maria db"
bad_password="password 123456789 qwerty azerty pass"

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

# --- GOES INTO THE MARIADB DATABASE LOCATION ---
cd /var/lib/mysql

# --- CHECK IF ENV VARS EXIST ---
if [ "$MARIADB_USER" == "" ]; then
	printf "\x1b[31m[!] Missing environment 'MARIADB_USER' variable detected\n\x1b[0m" 1>&2
	exit 1
elif [ "$MARIADB_PASSWD" == "" ]; then
	printf "\x1b[31m[!] Missing environment 'MARIADB_PASSWD' variable detected\n\x1b[0m" 1>&2
	exit 1
elif [ "$MARIADB_DOMAIN" == "" ]; then
	printf "\x1b[31m[!] Missing environment 'MARIADB_DOMAIN' variable detected\n\x1b[0m" 1>&2
	exit 1
fi

# --- CHECK THE WEAKNESS OF THE USER AND PASSWORD ---
for usr in $bad_username; do
	if [ "$MARIADB_USER" == "$usr" ]; then
		printf "\x1b[33m[!] The username '$usr' is common, this could lead to security issues\n\x1b[0m" 1>&2
	fi
done
for passwd in $bad_password; do
	if [ "$MARIADB_PASSWD" == "$passwd" ]; then
		printf "\x1b[33m[!] The password '$passwd' for the user '$MARIADB_USER' is weak, this could lead to serious security issues\n\x1b[0m" 1>&2
	fi
done

# --- INITIALIZED MARIADB ---
printf "[+] Loading MariaDB\n" 1>&2
check_file_exist "mysql.user"
mariadb-install-db --user=mysql --datadir=/var/lib/mysql 2>/dev/null

# --- STARTING MARIADB DAEMON ---
printf "[+] Initialized MariaDB daemon\n" 1>&2
/usr/bin/mariadbd-safe --datadir='/var/lib/mysql' &
sleep 3

# --- CONFIGURING THE DATABASE ---
printf "[+] Checking for existant database ...\n" 1>&2
check_file_exist "wordpress"
if [ $? -eq 0 ]; then
	cat > init.sql << EOF
ALTER USER 'root'@'mariadb'IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';
CREATE DATABASE IF NOT EXISTS wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
CREATE USER IF NOT EXISTS '$MARIADB_USER'@'mariadb' IDENTIFIED BY '$MARIADB_PASSWD';
GRANT ALL PRIVILEGES ON wordpress.* TO '$MARIADB_USER'@'mariadb';
FLUSH PRIVILEGES;
EOF
	mariadb -u root < ./init.sql
fi

# --- WAITING UNTIL THE CONTAINER STOP (INFINITE LOOP) ---
printf "[+] MariaDB successfully initialized\n" 1>&2
wait
