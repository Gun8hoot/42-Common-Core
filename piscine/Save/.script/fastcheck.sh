#!/bin/bash

# A mettre dans un fichier shell avec les perm d'execution et faire un alias dans le .zshrc 

ARGC=$#
NOM_ALIAS="fastcheck"

if [ ${ARGC} -ge 2 ]
then
	len="${#2}"
	git clone $1 $2 2>/dev/null
	cd $2
	norminette
	code .
	~/mini-moulinette/mini-moul.sh
	fi

else
	echo -e "\e[0;31m[!] Erreur : ${NOM_ALIAS} {lien repo} {nom du dossier}\e[0m"
fi
