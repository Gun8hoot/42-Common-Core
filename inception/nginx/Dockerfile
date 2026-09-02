FROM alpine:3.22
RUN apk update && \
	apk add nginx openssl
# Certificat : sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt

RUN mkdir -p /var/www/data

COPY ./nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off;"]
