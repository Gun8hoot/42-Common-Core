FROM alpine:3.22

# -- INITIALIZE CONTAINER --
RUN apk update && apk add php83-fpm php83-mysqli php83-mbstring wget
RUN mkdir -p /var/www/adminer
RUN adduser -D -H -S -G www-data www-data
RUN chown www-data: /var/www/adminer

# -- COPY FILES --
WORKDIR /var/www/adminer/
COPY ./www.conf /etc/php83/php-fpm.d/www.conf

# -- LAUNCH THE CONTAINER --
CMD ["php-fpm83", "-F"]
