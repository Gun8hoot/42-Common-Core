FROM alpine:3.22
RUN	apk update && \
	apk add mariadb unzip mariadb-client

RUN mkdir -p /var/lib/mysql/wordpress
RUN chown -R mysql:mysql /var/lib/mysql

RUN mkdir -p /run/mysqld
RUN chown mysql:mysql /run/mysqld
RUN chmod 755 /run/mysqld
RUN mkdir -p /etc/mysql/conf.d/
COPY mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf

EXPOSE 3306
COPY ./entrypoint.sh /tmp/entrypoint.sh
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
