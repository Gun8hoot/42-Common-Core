FROM alpine:3.22
RUN apk update && \
	apk add nginx openssl
# Certificat : sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt

# Create every folder
RUN mkdir -p /etc/nginx/sites-available
RUN mkdir -p /etc/nginx/sites-enabled

# Copy every config files
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./sites-available /etc/nginx/sites-available
COPY ./static /var/www/static


RUN rm -f /etc/nginx/sites-enabled/default

# Create a symlink for every vhost
RUN ln -s /etc/nginx/sites-available/kuma.nclavel.42.fr /etc/nginx/sites-enabled/kuma.nclavel.42.fr
RUN ln -s /etc/nginx/sites-available/nclavel.42.fr /etc/nginx/sites-enabled/nclavel.42.fr
RUN ln -s /etc/nginx/sites-available/static.nclavel.42.fr /etc/nginx/sites-enabled/static.nclavel.42.fr
RUN ln -s /etc/nginx/sites-available/adminer.nclavel.42.fr /etc/nginx/sites-enabled/adminer.nclavel.42.fr

# Port used by the container
EXPOSE 80 443

CMD ["nginx", "-g", "daemon off;"]
