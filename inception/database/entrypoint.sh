#!/bin/sh

bad_username="user usr root admin administrator mariadb maria db azerty qwerty a"
bad_password="password 123456789 qwerty azerty pass 123 a"

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

# ╔═══════════════════════════╗
# ║           CHECK           ║
# ╚═══════════════════════════╝

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

# ╔═════════════════════════╗
# ║           MAIN          ║
# ╚═════════════════════════╝

cd /var/lib/mysql

# --- INITIALIZED MARIADB ---
printf "[+] Loading MariaDB\n" 1>&2
check_file_exist "mysql.user"
if [ $? -eq 0 ]; then
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql 2>/dev/null
else
	mariadb-upgrade --user=mysql --datadir=/var/lib/mysql 2>/dev/null
fi

# --- STARTING MARIADB DAEMON ---
mariadbd -h $MARIADB_DOMAIN --user=mysql --datadir='/var/lib/mysql' &
until mariadb-admin ping --silent -h $MARIADB_DOMAIN; do
	sleep 1
done

daemon_password=$(tr -dc 'a-zA-Z0-9' < /dev/urandom | head -c 128)
# --- CONFIGURING THE DATABASE ---
cat > init.sql << EOF
CREATE DATABASE IF NOT EXISTS wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
CREATE USER IF NOT EXISTS 'root'@'$MARIADB_DOMAIN' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';
CREATE USER IF NOT EXISTS '$MARIADB_USER'@'$MARIADB_DOMAIN' IDENTIFIED BY '$MARIADB_PASSWD';
GRANT ALL PRIVILEGES ON wordpress.* TO '$MARIADB_USER'@'$MARIADB_DOMAIN';
ALTER USER IF EXISTS 'root'@'$MARIADB_DOMAIN' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';
FLUSH PRIVILEGES;
EOF
echo "here"
mariadb -h $MARIADB_DOMAIN -u root --skip-password < ./init.sql
echo "not here"

mariadb-admin shutdown -h $MARIADB_DOMAIN
sleep 2

# --- WAITING UNTIL THE CONTAINER STOP (INFINITE LOOP) ---
printf "[+] MariaDB successfully initialized\n" 1>&2
exec mariadbd --user=mysql --datadir='/var/lib/mysql'
