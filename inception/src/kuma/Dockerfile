FROM alpine:3.22
RUN apk update \
	&& apk add npm git

RUN git clone https://github.com/louislam/uptime-kuma.git /tmp/uptime-kuma
WORKDIR /tmp/uptime-kuma

COPY ./entrypoint.sh /tmp/entrypoint.sh
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
