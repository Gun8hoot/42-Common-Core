# -- IMPORTING BASE IMAGE --
FROM alpine:3.22

# -- INITIALIZE CONTAINER --
RUN apk update && apk add --no-cache \
	php83-fpm \
	php83-mysqli \
	php83-mbstring \
	php83-session \
	php83-openssl \
	wget

# -- Create the directory + changing the owner of the directory --
RUN	mkdir -p /var/www/adminer \
	&& chown nobody: /var/www/adminer

# -- COPY THE CONFIGURATION FILE --
COPY ./www.conf /etc/php83/php-fpm.d/www.conf

# -- LAUNCH THE CONTAINER --
CMD ["php-fpm83", "-F"]
