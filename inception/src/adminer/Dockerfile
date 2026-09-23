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

RUN if [ $(ls -l | wc -l) -eq 0 ]; then wget https://github.com/vrana/adminer/releases/download/v6.1.0/adminer-6.1.0.php /var/www/adminer; fi

EXPOSE 4444

# -- LAUNCH THE CONTAINER --
CMD ["php-fpm83", "-F"]
