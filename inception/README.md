epThis project has been created as part of the 42 curriculum by __nclavel__.

<div align=center>
	<h1>Inception</h1>

[User documentation](./docs/USER_DOC.md)
[Developper documentation](./docs/DEV_DOC.md)

</div>


<div align=center>
	<h2>Description : </h2>
</div>

### Virtual Machines vs. Docker
Virtual machines include a complete operating system for every instance. This provides strong isolation but requires more memory, storage, and processing power. Docker containers share the host operating system’s kernel, making them faster to start and more lightweight.
For this project, Docker was selected because it allows the application and its dependencies to run in an isolated and reproducible environment without the overhead of a full virtual machine. Virtual machines may be more appropriate when completely different operating systems or stronger isolation are required.

### Secrets vs. Environment Variables
Environment variables are convenient for storing configuration values such as ports, usernames, or development settings. However, sensitive information such as passwords, API keys, and certificates should not be stored directly in ordinary environment variables or committed to the source code.
Docker secrets provide a safer way to manage sensitive values because they are made available to containers only when required and are stored separately from the application code. Therefore, this project uses environment variables for non-sensitive configuration and secrets for confidential information.

### Docker Network vs. Host Network
A Docker network allows containers to communicate with one another using isolated virtual networking. Services can communicate by container or service name, while their ports remain separated from the host unless explicitly published.
Host networking removes this isolation and makes the container use the host machine’s network directly. It can provide slightly better network performance, but it reduces portability and isolation and can cause port conflicts.
This project uses a Docker network because the services need to communicate with each other while remaining isolated from the host system. Only the ports required by users or external services are exposed.

### Docker Volumes vs. Bind Mounts
Docker volumes are managed by Docker and are generally recommended for persistent application data, such as database files. They are portable, easier to manage, and less dependent on the host machine’s directory structure.
Bind mounts connect a specific directory or file on the host machine to a location inside the container. They are useful during development because changes made to source files on the host are immediately available inside the container. However, bind mounts depend on the host’s filesystem and may cause permission or compatibility problems.
This project uses Docker volumes for persistent data that must survive container removal. Bind mounts are used, where necessary, for development source code or configuration files that need to be edited directly on the host.

<div align=center>
	<h2>Instruction : </h2>
</div>

- Start every microservices
```sh
make up
```
- Stop every microservices
```sh
make down
```
- Rebuild every microservices
```sh
make re
```
- Reset microservices
```sh
make reset
```

<div align=center>
	<h2>Ressources : </h2>
</div>

| [Docker compose documentation](https://docs.docker.com/reference/compose-file/) | [Docker documentation](https://docs.docker.com/reference/dockerfile/) | [Alpine package manager](https://pkgs.alpinelinux.org/packages) |
| --- | --- | --- |
| [Guide to use VSFTPD](https://dev.to/sahillearninglinux/ultimate-guide-to-vsftpd-configuration-files-commands-and-secure-sftp-migration-170m) | https://www.cloudways.com/blog/install-redis-cache-wordpress/ |
