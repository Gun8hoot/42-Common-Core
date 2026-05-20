DC = docker compose

all: up

up:
	@printf "\e[0;32m[?] Starting Inception services ...\e[0m\n"
	@$(DC) up

down:
	@printf "\e[0;33m[?] Stoping Inception services ...\e[0m\n"
	@$(DC) down

re:
	@$(MAKE) down
	@printf "\e[0;33m[?] Rebuilding Inception services ...\e[0m\n"
	@$(DC) build
	@$(MAKE) up

.PHONY: up down re
