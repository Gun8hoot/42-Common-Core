FROM alpine:3.22
WORKDIR /tmp
RUN apk update && \
	apk add	lighttpd unzip apache2 php

COPY ./latest.zip /tmp/latest.zip
COPY ./install.sh /tmp/entrypoint.sh

# TEST WITHOUT NGINX
USER www-data
EXPOSE 443
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
