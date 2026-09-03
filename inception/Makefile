DC	= docker compose
D	= docker

all: up

up:
	@bash ./scripts/init.sh
	@bash ./scripts/check_env.sh
	@printf "\e[0;32m[?] Starting Inception services ...\e[0m\n"
	@mkdir -p ~/data/mariadb
	@mkdir -p ~/data/wordpress
	@$(DC) up -d
	@printf "\e[0;32m[+] Inception services have been launched ...\e[0m\n"

down:
	@printf "\e[0;33m[?] Stoping Inception services ...\e[0m\n"
	@$(DC) down
	@yes | $(D) network prune 1>/dev/null

re:
	@$(MAKE) down
	#@yes | $(D) system prune -a --volumes  || true
	@printf "\e[0;33m[?] Rebuilding Inception services ...\e[0m\n"
	@$(DC) build -q
	@$(MAKE) up

.PHONY: up down re
