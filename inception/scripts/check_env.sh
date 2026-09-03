#!/bin/bash

function banner {
	printf """\e[0;34m   ________  ________________ __ _____   ________   _______   ___    __
  / ____/ / / / ____/ ____/ //_//  _/ | / / ____/  / ____/ | / / |  / /
 / /   / /_/ / __/ / /   / ,<   / //  |/ / / __   / __/ /  |/ /| | / /
/ /___/ __  / /___/ /___/ /| |_/ // /|  / /_/ /  / /___/ /|  / | |/ /
\____/_/ /_/_____/\____/_/ |_/___/_/ |_/\____/  /_____/_/ |_/  |___/
        --- CHECKING .ENV FILE ---\e[0m\n"""
}

function check_password {
	bad_password="password 123456789 qwerty azerty pass 123 dev test"
	if [ ${#2} -lt 7 ]; then
		printf "\x1b[33m[!] The size of your password for '$1' is short ${#2} character\n\x1b[0m" 1>&2
	fi

	for usr in $bad_password; do
		if [ "$2" == "$usr" ]; then
			printf "\x1b[33m[!] Your environment variable '$1' have a very weak password = '$2'\n\x1b[0m" 1>&2
			return 1
		fi
	done
	return 0
}

function check_username {
	bad_username="user usr root admin administrator mariadb maria db azerty qwerty a"

	for usr in $bad_username; do
		if [ "$2" == "$usr" ]; then
			printf "\x1b[33m[!] The username '$2' for '$1' is common, this could lead to security issues\n\x1b[0m" 1>&2
			return 1
		fi
	done
	return 0
}

function main {
	TMP_FILEPATH="/tmp/inception_check"
	ISSUE=0
	NB=0

	# // Display a banner
	banner

	# // Check if the .env file exist
	if [ ! -f ./.env ]; then
		echo "Missing .env file"
		exit 1
	fi

	# // Read the file line by line
	while IFS= read -r line; do
		# // Skip empty line and comment who use #
		if [ "$(echo $line | xargs | cut -b 1)" == "#" ] || [ -z "$line"  ]; then
			echo "$line" >> $TMP_FILEPATH
			continue
		fi

		# // Increase the number of environment variable counted \\
		NB=$(($NB+1))

		# // Remove every ", ' and $ on the line \\
		line=$(echo "$line" | tr -d $'\'')
		line=$(echo "$line" | tr -d $'\"')
		line=$(echo "$line" | tr -d $'$"')
		SAVE=$line
		SAVE=$(echo "$SAVE" | cut -d'#' -f1 | xargs)

		# // Split the env vars from the first = \\
		key="${SAVE%%=*}"
		value="${SAVE#*=}"

		# // If the variable is a password, check it
		if [[ "$key" == *"PASSWORD"* ]] || [[ "$key" == *"password"* ]]; then
			check_password $key $value
			if [ $? -eq 1 ]; then
				ISSUE=$(($ISSUE + 1))
			fi
			# // If the variable is a username, check it
		elif [[ "$key" == *"USERNAME"* ]] || [[ "$key" == *"username"* ]]; then
			check_username $key $value
			if [ $? -eq 1 ]; then
				ISSUE=$(($ISSUE + 1))
			fi
		elif [ "$key" == "MARIADB_DOMAIN" ]; then
			if [ "$value" == "localhost" ]; then
				printf "\e[0;31m[!] The value $value of $key is forbidden\n\e[0m"
				exit 1
			fi
		fi
		# // Append the treated SAVE on a temporary file
		echo "$line" >> $TMP_FILEPATH
	done < .env

	# // Write a message with the number of error found
	if [ $ISSUE -gt 0 ]; then
		printf "\e[0;31m[!] Minor issue found : $ISSUE/$NB\n\e[0m"
	fi

	mv $TMP_FILEPATH .env
	rm -f $TMP_FILEPATH
}

main
