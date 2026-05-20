FROM alpine:3.22
RUN	apk update &&\
	apk add mariadb unzip mariadb-client

RUN mkdir -p /var/lib/mysql/wordpress
RUN chown mysql:mysql /var/lib/mysql

RUN mkdir -p /run/mysqld
RUN chown mysql:mysql /run/mysqld
RUN chmod 755 /run/mysqld

COPY ./entrypoint.sh /tmp/entrypoint.sh
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
