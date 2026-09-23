NAME = inception

ROOT_STATUS := ${EUID}

$(NAME): up

all: $(NAME)

up:
	@bash ./scripts/init.sh
	@bash ./scripts/check_env.sh
	@printf "\e[0;32m[?] Starting Inception services ...\e[0m\n"
	@mkdir -p ~/data/mariadb
	@mkdir -p ~/data/wordpress
	@docker compose -f ./srcs/docker-compose.yml up -d
	@printf "\e[0;32m[+] Inception services have been launched ...\e[0m\n"

down:
	@printf "\e[0;33m[?] Stoping Inception services ...\e[0m\n"
	@docker compose -f ./srcs/docker-compose.yml down
	@yes | docker network prune 1>/dev/null

re:
	@$(MAKE) down
	@yes | docker network prune
	@printf "\n\e[0;33m[?] Rebuilding Inception services ...\e[0m\n"
	@docker compose -f ./srcs/docker-compose.yml build
	@$(MAKE) up

reset:
	@$(MAKE) down
	@yes | docker system prune -a --volumes
	@sudo rm -rf ~/data

.PHONY: up down re reset
