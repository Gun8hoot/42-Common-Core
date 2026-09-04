NAME = inception

$(NAME): up

all: $(NAME)

up:
	@bash ./scripts/init.sh
	@bash ./scripts/check_env.sh
	@printf "\e[0;32m[?] Starting Inception services ...\e[0m\n"
	@mkdir -p ~/data/mariadb
	@mkdir -p ~/data/wordpress
	@docker compose up -d
	@printf "\e[0;32m[+] Inception services have been launched ...\e[0m\n"

down:
	@printf "\e[0;33m[?] Stoping Inception services ...\e[0m\n"
	@docker compose down
	@yes | docker network prune 1>/dev/null

re:
	@$(MAKE) down
	@yes | docker prune network || true
	@printf "\e[0;33m[?] Rebuilding Inception services ...\e[0m\n"
	@docker compose build -q
	@$(MAKE) up

reset:
	@$(MAKE) down
	@sudo rm -rf ~/data
	@yes | docker compose  system prune -a --volumes  || true
	@docker compose volumes prune -q || true

.PHONY: up down re
