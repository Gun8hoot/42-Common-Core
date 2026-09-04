FROM alpine:3.22

ARG FTP_PASSWORD=defaultpassword

RUN apk update && apk --no-cache add vsftpd openssl shadow

COPY ./vsftpd.conf /etc/vsftpd.conf
RUN mkdir -p /srv/ftp

# -- INITIALIZE USER --
RUN groupadd ftp_gr
RUN useradd  -d /srv/ftp/ user

RUN usermod -aG ftp_gr ftp
RUN usermod -aG ftp_gr user
RUN usermod -aG ftp_gr vsftp

COPY ./entrypoint.sh /tmp/entrypoint.sh
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
