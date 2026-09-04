FROM alpine:3.22
RUN apk update && apk add gitea

# RUN adduser gitea -h /srv/gitea -D -H
RUN mkdir -p /srv/gitea
RUN chown -R gitea: /srv/gitea

USER gitea
CMD ["sleep", "99999"]
# CMD ["gitea"]
