FROM alpine:3.22
RUN	apk update &&\
	apk add mariadb unzip mariadb-client

COPY ./entrypoint.sh /tmp/entrypoint.sh
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
