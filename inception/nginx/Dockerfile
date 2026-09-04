FROM alpine:3.22
RUN apk update && \
	apk add nginx openssl
# Certificat : sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt

# Create every folder
RUN mkdir -p /var/www/data
RUN mkdir -p /etc/nginx/sites-available
RUN mkdir -p /etc/nginx/sites-enabled

# Copy every config files
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./kuma.nclavel.42.fr /etc/nginx/sites-available/kuma.nclavel.42.fr
COPY ./nclavel.42.fr /etc/nginx/sites-available/nclavel.42.fr

RUN rm -f /etc/nginx/sites-enabled/default

# Create a symlink for every vhost
RUN ln -s /etc/nginx/sites-available/kuma.nclavel.42.fr /etc/nginx/sites-enabled/kuma.nclavel.42.fr
RUN ln -s /etc/nginx/sites-available/nclavel.42.fr /etc/nginx/sites-enabled/nclavel.42.fr

CMD ["nginx", "-g", "daemon off;"]
