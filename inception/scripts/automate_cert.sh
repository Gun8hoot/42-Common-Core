mkdir -p ./sources/nginx/.secret/
mkdir -p ./sources/ftp/.secret/

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout ./sources/nginx/.secret/nginx.key -out ./sources/nginx/.secret/nginx.crt
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout ./sources/ftp/.secret/vsftpd.key -out ./sources/ftp/.secret/vsftpd.crt
