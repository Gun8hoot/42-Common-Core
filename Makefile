DC	= docker compose
D	= docker

all: up

up:
	@printf "\e[0;32m[?] Starting Inception services ...\e[0m\n"
	@mkdir -p ~/data
	@$(DC) up
	@printf "\e[0;32m[+] Inception services have been launched ...\e[0m\n"

down:
	@printf "\e[0;33m[?] Stoping Inception services ...\e[0m\n"
	@$(DC) down
	@yes | $(D) network prune 1>/dev/null

re:
	@$(MAKE) down
	@printf "\e[0;33m[?] Deleting old volumes ...\e[0m\n"
	@$(D) volume rm $(docker volume ls | awk '{print $2}' | tail -n+2) || true
	@printf "\e[0;33m[?] Rebuilding Inception services ...\e[0m\n"
	@$(DC) build
	@$(MAKE) up

.PHONY: up down re
