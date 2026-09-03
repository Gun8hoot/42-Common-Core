FROM alpine:3.22
RUN apk update && \
	apk add	lighttpd unzip\
		php83-fpm \
		php83 \
		php83-mysqli \
		php83-pdo \
		php83-pdo_mysql \
		php83-gd \
		php83-xml \
		php83-curl \
		php83-json \
		php83-opcache \
		php83-zlib \
		mariadb-client

WORKDIR /tmp

# wget https://wordpress.org/latest.tar.gz -O ./sources/wordpress/latest.tar.gz
COPY ./install.sh /tmp/entrypoint.sh
COPY ./www.conf /etc/php83/php-fpm.d/www.conf

RUN adduser -D -H -S -G www-data www-data
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
