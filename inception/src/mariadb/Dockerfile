# -- IMPORTING BASE IMAGE --
FROM alpine:3.22
RUN	apk update && \
	apk add mariadb \
	unzip \
	mariadb-client

# -- CREATE DIRECTORY EVERY DIRECTORY --
RUN mkdir -p /var/lib/mysql/wordpress \
	&& mkdir -p /run/mysqld \
	&& mkdir -p /etc/mysql/conf.d/

# -- CHANGE OWNER OF THE SOCKET AND DATABASE --
RUN chown -R mysql:mysql /var/lib/mysql \
	&& chown mysql:mysql /run/mysqld \
	&& chmod 755 /run/mysqld

# -- COPY EVERY USEFULL FILES --
COPY mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf

# -- ENTRYPOINT --
COPY ./entrypoint.sh /tmp/entrypoint.sh
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
