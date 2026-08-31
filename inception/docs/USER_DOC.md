<div align=center>
	<h1>USER DOCUMENTATION</h1>
</div>

## REQUIREMENT :
- docker 
- docker-compose

## SERVICES AVAILABLES :

### NGINX :
A powerful open source software that can do reverse proxy, load balancer, mail proxy and http cache.
### WORDPRESS :
A free and open sources web Content Management System (CMS)</p>
### MARIADB :
A free and open sources database management that handle wordpress database
### VSFTPD :
An open source FTP server

## MANAGE DOCKER CONTAINER :
- Start every containers with :
```sh
docker compose up # Dont forget sudo if you are using a regular user
```
- Stop every containers with :
```sh
docker compose down # Dont forget sudo if you are using a regular user
```
- See container status :
```sh
docker compose ps
```

## MANAGE CREDENTIAL :
To easly handle credential you need to create a .env file at the root of the project directory. On this .env file you can:
- FTP_PASSWORD : The password to connect on the user "ftp" using an ftp client
- MARIADB_USERNAME : The username of the administrator of the database
- MARIADB_PASSWORD : The password of the administrator of the database
