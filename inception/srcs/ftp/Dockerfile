# -- IMPORT BASE IMAGE --
FROM alpine:3.22

# -- COPY EVERY USEFULL FILES --
RUN apk update && apk --no-cache add vsftpd \
	openssl \
	shadow

COPY ./vsftpd.conf /etc/vsftpd.conf
RUN mkdir -p /srv/ftp

# -- CREATE USER "wordpress" --
RUN useradd  -d /srv/ftp/ wordpress

# -- ADD EVERY USER INTO THE GROUP "ftp_gr" --
RUN groupadd ftp_gr
RUN usermod -aG ftp_gr wordpress

EXPOSE 20 40000-40100

# -- ENTRYPOINT --
COPY ./entrypoint.sh /tmp/entrypoint.sh
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
