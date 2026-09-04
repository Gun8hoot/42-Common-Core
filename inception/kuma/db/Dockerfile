FROM alpine:3.22
RUN	apk update && \
	apk add mariadb unzip mariadb-client

# -- CREATE DIRECTORY --
RUN mkdir -p /var/lib/mysql/kuma
RUN mkdir -p /run/mysqld
RUN mkdir -p /etc/mysql/conf.d/

# -- ADJUST PERMISSION --
RUN chown -R mysql:mysql /var/lib/mysql
RUN chown mysql:mysql /run/mysqld
RUN chmod 755 /run/mysqld

# -- COPY EVERY USEFULL FILES --
COPY mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY ./entrypoint.sh /tmp/entrypoint.sh

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
