FROM alpine:3.22

ARG FTP_PASSWORD=defaultpassword

RUN apk update && apk --no-cache add vsftpd openssl shadow
RUN mkdir -p /srv/ftp
RUN mkdir -p /var/ftp/{cert,key}

COPY ./vsftpd.conf /etc/

RUN groupadd ftp_gr
RUN echo "ftp:${FTP_PASSWORD}" | chpasswd && usermod -d /srv/ftp ftp
RUN usermod -aG ftp_gr ftp
RUN chown ftp:ftp_gr /srv/ftp/

EXPOSE 20
EXPOSE 21
EXPOSE 40000-40100

COPY ./entrypoint.sh /tmp/entrypoint.sh
RUN chmod +x /tmp/entrypoint.sh
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
