FROM alpine:3.22

# -- INITIALIZE CONTAINER --
RUN apk update
RUN apk add --no-cache \
    php83-fpm \
    php83-mysqli \
    php83-mbstring \
    php83-session \
    php83-openssl \
    wget
RUN mkdir -p /var/www/adminer
# RUN adduser -D -H -S -G nobody nobody
RUN chown nobody: /var/www/adminer

# -- COPY FILES --
COPY ./www.conf /etc/php83/php-fpm.d/www.conf

# -- LAUNCH THE CONTAINER --
CMD ["php-fpm83", "-F"]
