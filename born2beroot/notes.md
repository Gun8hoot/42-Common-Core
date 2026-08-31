# Born2BeRoot

---

## Installation

---

- Debian est stable et sécurisé pour les systèmes + c’est accessible
- On doit avoir aux moins 2 partitions chiffrer en LVM (Logical Volume Manager)
    - Méthode alternative qui pour gérer le système de stockage d’un système
    - À la place de créer des partitions, lorsque l’on utilise LVM, on crée des volumes logiques
    - On ne peut pas utiliser de LVM pour le /boot car grub (bootloader le plus frequent) ne permet pas de lire les LVM
    - Les LVM sont très pratiques, car ils permettent de resize la taille des volumes ou des groupes facilement
    - Il est important de chiffrer le LVM pour la sécurité. Par exemple, sur linux il est facile de changer des mots de passe si on access a notre disque (`init /bin/bash` sur les options de grun pour ceux que ça intéresse/

<aside>
💡

[https://linuxhandbook.com/lvm-guide/](https://linuxhandbook.com/lvm-guide/)

</aside>

### Partitionnement

---

- Le / est l’endroit principal pour l’OS, il contient tous les fichiers systèmes
- Le /home est l’endroit où le dossier des utilisateurs sont créés (leurs dossiers, documents, téléchargements, etc…)
    - On est pas obliger de mettre le /home dans une autre partition. Generalement il est dans la meme partition que le /
- le /boot est la partition qui contient les fichiers du bootloader (”logiciel” qui permet de lancer le pc avec des options de lancement). Comme dit plus haut, le bootloader le plus utiliser est grub
- Le /etc contient plein de fichier de configuration comme l’hostname, ssh ou encore pam
- Le /usr contient tous les bianair et librairie des utilisateur normaux
- Le /var va contenir le cache des application, log. Resumer de maniere grossiere, c’est comme le /tmp, mais les donnee ne sont pas supprimer toutes seules
- Le /srv va contenir toutes les donnees des services du type server http, ftp ou encore icmp
- La partition Swap est un endroit réservé qui sert de RAM si toute la RAM est utilisé
    - Pas obligatoire, mais recommander lorsqu'il n’y a pas beaucoup de RAM installé dans le PC
    - Elle est EXTREMEMENT plus lente que la vraie RAM, c’est pour ça qu'elle est utilisée de manière general
- Il y a plusieurs interet a faire des partition separer :
    - Utiliser des systeme de fichier different (ext4, btrfs, fat32, etc)
    - Charger des partition plus rapidement
    - Separer par exemple le / et le /root pour des raison de securiter
    - avoir plusieur fois les meme partition genre cree des /usr pour chaque utilisateur
    - Imaginon que le / est a 100%, on veux quand même avoir les log de /var/log qui s’écrivent
- sr0 inteface de lecteur dvd donc balec

<aside>
❓

Dans le sujet ils parlent de SELinux et AppArmor. Les deux sont des modules de securiter pour le noyau Linux qui permet de limiter ce que fait les application sur le systeme.

Le kernel (noyau) est une des partie les plus basse et crutial des OS. Il s’occupe de gerer les ressources de l’ordinateur et permet de aux different composant, materiel et logiciel de communiquer entre eux. 

</aside>

<aside>
💡

[https://linuxhandbook.com/linux-directory-structure/](https://linuxhandbook.com/linux-directory-structure/)

[https://fr.wikipedia.org/wiki/Noyau_de_système_d'exploitation](https://fr.wikipedia.org/wiki/Noyau_de_syst%C3%A8me_d%27exploitation)

</aside>

## Configuration

---

- Sudo (substitute user do) est un logiciel qui permet de faire des actions de su sur le système sans être connecté à l’utilisateur root.
    - Permet d’avoir une traçabilité lorsque des actions sont faites en superuser
    - On install sudo grâce a `apt install sudo`
        - IL FAUT SE CONNECTER AVEC L’UTILISATEUR ROOT POUR POUVOIR INSTALLER DES LOGICIEL SANS SUDO : `logout` et connection avec root et mots de passe root
    - Pour que notre user ayant les permissions d’utiliser sudo, il faut l’ajouter au groupe sudo `usermod -aG {USER_NAME} sudo`
        - Après avoir ajouté un utilisateur à notre groupe, il faut redémarrer la VM avec `reboot`
    - Pour configurer sudo, il faut créer un fichier dans `/etc/sudoers.d/{NOM_FICHIER}`, moi pour ma vm je l’ai juste appeller config
        - passwd_tries limite le nombre d’essais avant de quitter l’authentification
        - badpass_message permet de mettre un message customiser si le mdp entré est mauvais
        - logfile permet de definir le chemin ou sudo doit écrire ses log
        - requiretty paramettre mis pour la securiter, permet que le daemon de ssh exige une connection avant d’executer une commande sudo
        - secure_path permet de restreindre le $PATH des sudo
            - $PATH est une variable d’environnement défini dans zsh, bash, fish et tous les autres shell. Elle permet d’indiquer l’endroit ou se trouve les executable des programmes. Pour trouver l’emplacement des binaire qui sont présentes dans notre path on peut faire `which {nom executable}`
        
        <aside>
        ❓
        
        [https://stackoverflow.com/questions/67985925/why-would-i-want-to-require-a-tty-for-sudo-whats-the-security-benefit-of-requi](https://stackoverflow.com/questions/67985925/why-would-i-want-to-require-a-tty-for-sudo-whats-the-security-benefit-of-requi)
        
        </aside>
        
    
    <aside>
    💡
    
    [https://www.it-connect.fr/commande-sudo-comment-configurer-sudoers-sous-linux/](https://www.it-connect.fr/commande-sudo-comment-configurer-sudoers-sous-linux/)
    
    </aside>
    
     
    
- Le pare-feu/firewall sert à limiter les connections qui sort ou qui rentre sur un système/réseau privée
    - Sur debian il faut installer `ufw`
    - Bien verifier si ufw se lance au démarrage avec `systemctl status ufw`
        - Si il n’est pas activé `ufw enable`
    - On ajoute une regle au pare-feux avec `ufw allow {port}`
- SSH est un programme et un protocole de communication qui permet de donner l’acces a un shell à un autre pc a distance
    - Il utilise le port 22 habituellement, mais nous on modifie le port pour mettre le port 4242
    - On modifie le port de ssh dans `/etc/ssh/sshd_config` (bien retirer le #)
    - On authorise les connection entrante et sortant sur le nouveau port de ssh avec `ufw allow {PORT}`
- La commande `wall` permet de faire afficher un message sur tous les terminaux des utilisateur qui sont connecter. Cepandant il ne permet pas d’afficher aux utilisateur qui sont connecter en ssh. Il faut l’utiliser pour afficher le script depuis cron
- Config du mots de passe
    - On modifie la periode des mots de passe dans /etc/login.defs
        - PASS_MAX_DAY 9999 → 30 ; Nombre de jours avant que le mdp perime
        - PASS_MIN_DAY 0 → 2 ; Nombre de jours avant de pouvoir changer de mdp
        - PASS_WARN_AGE 7 ; Permet d’avertir l’utilisateur que son mdp va perimer dans 7j
    - Il faut telecharger une librarie pour le systeme qui permet de verifier si un mdp est fort (`libpam-pwquality`)
        - Modifier le fichier `/etc/pam.d/commun-password`
            - retry=3 ; Nombre de tentatives avant que l’on sorte du programme pour nombre trop nombreux de tentative de mots de passe
            - minlen=10 ; taille minimum que le mdp doit avoir
            - ucredit=-1 ; doit avoir aux moins une lettre en maj
            - dcredit=-1 ; doit avoir aux moins un chiffre
            - maxrepeate=3 ; Nombre de fois où un caractère peut être répété
            - rejectusername ; On compte le mpd comme invalide si il contient le nom de l’utilisateur
            - difok=7 ; Doit avoir 7 caractere de difference entre l’ancien et le nouveau mdp
            - enforce_for_root ; s’applique aussi au root

### BONUS

---

<aside>
⚠️

IL FAUT SAVOIR DES LE DEBUT SI ON FAIT LES BONUS POUR BIEN FAIRE LES PARTITION DU BONUS

</aside>

- Le bonus nous demande d’installer 3 services pour faire fonctionner notre site wordpress:
    - Lighttpd: Permet d’heberger des servers web. Alternative a Apache ou Nginx
    - MariaDB: Permet de gerer des bases de donnees SQL
    - PHP: Language de programmation pour les application web qui a besoin d’un interpreteur pour fonctionner. Donc ici on install l’interpreteur pour le php
- Pour configurer mariaDB on fait
    
    ```bash
    sudo mariadb-secure-installation
    ```
    
    ```
    Switch to unix_socket authentication [Y/n] y
    Change the root password? [Y/n] n
    Remove anonymous users? [Y/n] y
    Disallow root login remotely? [Y/n] y
    Remove test database and access to it? [Y/n] y
    Reload privilege tables now? [Y/n] y
    ```
    
- On doit ensuite lancer MariaDB et créé la base de donnée
    
    ```sql
    MariaDB [(none)]> CREATE DATABASE db;
    ```
    
- On doit mettre les permissions a notre db avec un mot de passe
    
    ```sql
    MariaDB [(none)]> GRANT ALL ON db.* TO 'nclavel'@'localhost' IDENTIFIED BY 'password' WITH GRANT OPTION;
    ```
    
- On recharge notre db
    
    ```sql
    MariaDB [(none)]> FLUSH PRIVILEGES;
    ```
    
- On se connecte à notre base de donnée
    
    ```bash
    mariadb -u nclavel -p
    ```
    
- On installe les paquets `php-cgi` et `php-mysql`
    - Une CGI (Common Gateway Interface) est un protocole qui permet de transférer des données entre un serveur web et une application (ici lighttpd et php/mariasql)
    - mysql est un logiciel obsolète qui permet de gérer des bases de donnée en sql. Le paquet `php-mysql` permet de traiter des bases de donnée en php
- Wget permet de retirer du contenu d’un serveur web
    - Le nom est une contraction de “World Wide Web” et get
- On télécharge les fichiers utiles à WordPress avec :
    
    ```bash
    sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html
    # Le flag -P permet de mettre le fichier .tar.gz dans le /var/www/html
    ```
    
- On extrait le contenu de l’archive
    
    ```bash
    sudo tar -xzvf /var/www/html/latest.tar.gz
    # x = extract
    # z = flag pour les archive en gz
    # v = Imprime a l'ecran chaque fichier extrait
    # f = Precise l'archive a decompresser 
    ```
    
- On move tous à la racine de notre site (/var/www/html/)
    
    ```bash
    sudo cp -r /var/www/html/wordpress/* /var/www/html/
    ```
    
- On doit modifier le fichier de config du wordpress
    
    ```bash
    sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
    sudo vim /var/www/html/wp-config.php
    
    # ON MODIFIE CES LIGNE LA 
    define ( 'DB_NAME', '<NOM DE LA DB>')
    define ( 'DB_USER', '<NOM DU USER>')
    define ( 'DB_PASSWORD', '<PASSWORD DE LA DB>')
    ```
    
- Si c’est pas deja fait, il faut activer les requete entrante et sortant du port 80 du firewall
    
    ```bash
    ufw allow 80
    # Check apres pour voir si la regle a bien ete ajouter
    ufw status
    ```
    

<aside>
🌐

[https://mariadb.com/docs/server/reference/sql-statements/data-definition/create/create-database](https://mariadb.com/docs/server/reference/sql-statements/data-definition/create/create-database)

</aside>

- SQL tuto 2spi
    - Le sql sert stocker et manipuler des bases de donnee
    - `SHOW DATABASES;` voir les bases de donnees cree
    - `DROP DATABASE <DB_NAME>;` supprime une base de donnee
    - `IF NOT EXIST` condition si
- En cas d’erreur lighttpd `error-code 255/EXCEPTION`
    
    Si jamais quand on fait `sudo systemctl status lighttpd` il y a marqué “loaded” mais c’est en **failed** dans active, il faut checker si Debian n'a pas installé `apache2` , un autre service de server web.
    
    ```bash
    sudo dpkg -l | grep apache
    # Si il trouve des package de apache
    sudo apt remove apache*
    
    # Si jamais il y a besoin de voir les log de lighttpd : 
    sudo journalctl -u lighttpd.service -b
    ```
    
- On active les different modules pour lighttpd

```bash
sudo lighty-enable-mod fastcgi
sudo lighty-enable-mod fastcgi-php
sudo service lighttpd force-reload
```

### FTP Server

---

- FTP (File Transfert Protocole) est un protocole de transfert de fichier. Il permet de copier des fichiers d’un ordinateur à des autres. Il utilise le port 20 et 21 comme port active (transfert des message) et une range de port choisi en port passif. Precisement, le port 21 transmet les command et reponse, le port 20 permet le transfert de fichier en mode actif et la range choisi transmet les fichiers en passif.
    - En actif, le client ouvre un port et attend chaque reponse du server. Utiliser uniquement de l’actif peut poser des problèmes de sécurité pour le client et avoir des probleme si le client a un firewall
    - En passif toutes les requêtes passe sur un port du server. On lui regle une range de port pour ne pas surcharger le port
- Installer vsftpd
    
    ```bash
    sudo apt install vsftpd
    ```
    
- On regarde si `vsftpd`est lancer
    
    ```bash
    sudo systemctl status vsftpd
    
    # Si il est pas lancer
    sudo systemctl --enable vsftpd
    ```
    
- Il faut autoriser le port 20 et 21 pour que ftp marche
    
    ```bash
    sudo ufw allow 21/tcp
    ```
    
- On doit ensuite creer un nouvel utilisateur pour notre ftp
    
    ```bash
    sudo adduser ftp_user
    ```
    
- Pour des raisons de sécurité on désactive la connection via ssh de cet utilisateur
    
    ```bash
    # DANS /etc/ssh/sshd_config
    DenyUsers ftp_user
    ```
    
- On redémarre ssh
    
    ```bash
    sudo systemctl restart sshd
    ```
    
- On cree ensuite le dossier ou les fichier transferer en ftp vont etre
    
    ```bash
    # Perso je l'ai mis a la racine mais vous le mettait ou vous voulez
    mkdir /ftp
    ```
    
- On met les permission d’ecriture pour les user root et le group ftp
    
    ```bash
    sudo chown root:ftp /ftp
    ```
    
- On peux maintenant configurer notre server ftp
    
    ```bash
    anonymous_enable=NO     # Sert a ne pas pouvoir se connecter avec anonymous:anonymous
    local_enable=YES        # Sert a se connecter grace a nos compte user
    write_enable=YES        # Permet d'interdire l'utilisation de commande qui change le system de fichier
    local_root=/ftp         # Emplacement des fichier present sur le server ftp
    ```