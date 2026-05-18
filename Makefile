DC = docker compose

all: up

up:
	@printf "\e[0;32mStarting Inception services ...\e[0m\n"
	@$(DC) up

down:
	@printf "\e[0;33mStoping Inception services ...\e[0m\n"
	@$(DC) down

re:
	@printf "\e[0;33mRebuilding Inception services ...\e[0m\n"
	$(MAKE) down
	$(DC) build
	$(MAKE) up

.PHONY: up down re
