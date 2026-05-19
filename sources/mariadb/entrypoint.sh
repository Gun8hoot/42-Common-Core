#!/bin/sh

function check ()
{
	bad_username="user usr root admin administrator mariadb maria db"
	bad_password="password 123456789 qwerty azerty pass"

	if [ "$MARIADB_USER" == "" ]; then
		printf "\x1b[31m[!] Missing environment 'MARIADB_USER' variable detected\n\x1b[0m" 1>&2
		exit 1
	elif [ "$MARIADB_PASSWD" == "" ]; then
		printf "\x1b[31m[!] Missing environment 'MARIADB_PASSWD' variable detected\n\x1b[0m" 1>&2
		exit 1
	fi

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
}

cd /var/lib/mysql

check
for file in *; do
	if [ "$file" != "*" ]; then
		echo $file
	fi
done

cat > init.sql << EOF
CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
CREATE USER '$MARIADB_USER'@'127.0.0.1' IDENTIFIED BY '$MARIADB_PASSWD';
GRANT ALL PRIVILEGES ON wordpress.* TO '$MARIADB_USER'@'127.0.0.1';
FLUSH PRIVILEGES;
EOF

rc-service mariadb start

sleep 3

mariadb -u root < ./init.sql
