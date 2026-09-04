FROM alpine:3.22
RUN apk update && apk add postgresql17 postgresql17-client

COPY ./postgresql.conf /etc/postgresql/

# ENTRYPOINT
COPY ./entrypoint.sh /tmp/entrypoint.sh
RUN chmod u+x /tmp/entrypoint.sh
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
