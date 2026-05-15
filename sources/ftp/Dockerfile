FROM alpine:3.22

RUN apk update && apk add vsftpd openssl
RUN mkdir -p /srv/ftp
RUN mkdir -p /var/ftp/{cert,key}

COPY ./vsftpd.conf /etc/
COPY ./.secret/vsftpd.key /var/ftp/key/
COPY ./.secret/vsftpd.crt /var/ftp/cert/

# RUN chown ftp:ftp /srv/ftp
# USER ftp
# RUN ls -al /srv


EXPOSE 20-21
EXPOSE 40000-40100

CMD ["vsftpd", "/etc/vsftpd.conf"]
