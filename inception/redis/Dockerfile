FROM alpine:3.22
RUN apk add redis

COPY ./redis.conf /etc/

# CMD ["sleep", "999999"]
CMD ["redis-server", "/etc/redis.conf"]
