FROM alpine:3.22
RUN apk update && apk add php83-fpm php83-mysqli php83-mbstring wget

RUN adduser -D -H -S -G www-data www-data
RUN mkdir -p /var/www/adminer
RUN chown www-data: /var/www/adminer

WORKDIR /var/www/adminer/
COPY ./www.conf /etc/php83/php-fpm.d/www.conf

CMD ["php-fpm83", "-F"]
