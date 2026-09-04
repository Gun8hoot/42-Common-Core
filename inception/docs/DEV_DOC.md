<div align=center>
	<h1>DEV DOCUMENTATION</h1>
</div>

## Infrastructure overview

This project runs a WordPress-based web infrastructure using Docker Compose. The services are connected through the `MainNet` bridge network and are built from their respective directories:

- **nginx** — HTTPS reverse proxy and web server
- **mariadb** — WordPress database
- **wordpress** — WordPress application
- **ftp** — Optional FTPS server for file transfers
- **adminer** — Optional database administration interface
- **redis** — Optional Redis service for caching
- **kuma** — Optional monitoring dashboard
- **kuma-mariadb** — MariaDB database used by Kuma

The mandatory services are:

- `nginx`
- `mariadb`
- `wordpress`

The remaining services are optional bonus services, but they are defined in the Compose file and start when the full stack is launched.

## Prerequisites

Install the following software before starting the project:

- Docker Engine
- Docker Compose plugin
- GNU Make
- Git

Verify the installations:

```bash
docker --version
docker compose version
make --version
git --version
```

The project should be run on a Linux environment or another system that supports Docker bind mounts and the required network and port configuration.

The following host ports must be available:

| Port | Service | Purpose |
|---:|---|---|
| `80` | nginx | HTTP |
| `443` | nginx | HTTPS |
| `21` | ftp | FTP control connection |
| `40000-40100` | ftp | Passive FTP connections |

If a port is already in use, stop the conflicting service or update the port mapping in the Compose file.

## Project structure

The infrastructure expects a layout similar to the following:

```text
.
├── Makefile
├── docker-compose.yml
├── .env
├── .cert/
│   ├── nginx.crt
│   ├── nginx.key
│   ├── vsftpd.crt
│   └── vsftpd.key
├── nginx/
│   ├── Dockerfile
│   └── static/
├── database/
│   └── Dockerfile
├── wordpress/
│   └── Dockerfile
├── ftp/
│   └── Dockerfile
├── adminer/
│   ├── Dockerfile
│   └── frontend/
├── redis/
│   └── Dockerfile
└── kuma/
    ├── Dockerfile
    └── db/
        └── Dockerfile
```

The Compose file may be named differently in the repository. Replace `docker-compose.yml` in the commands below with the actual filename if necessary.

## Environment configuration

Create a `.env` file in the project root. Docker Compose reads the variables in this file when creating the containers and bind-mounted volumes.

Example:

```dotenv
MARIADB_USERNAME=wordpress
MARIADB_PASSWORD=change-this-password
MARIADB_ROOT_PASSWORD=change-this-root-password

FTP_PASSWORD=change-this-ftp-password

KUMA_USERNAME=kuma
KUMA_PASSWORD=change-this-kuma-password
KUMA_ROOT_PASSWORD=change-this-kuma-root-password
```

Use strong, unique passwords. Do not commit `.env` to version control.

Add the following entries to `.gitignore` if they are not already present:

```gitignore
.env
.cert/
```

The Compose configuration uses these variables as follows:

- `MARIADB_USERNAME` and `MARIADB_PASSWORD` configure the WordPress database user.
- `MARIADB_ROOT_PASSWORD` configures the MariaDB root account.
- `FTP_PASSWORD` configures the FTP account password.
- `KUMA_USERNAME`, `KUMA_PASSWORD`, and `KUMA_ROOT_PASSWORD` configure the Kuma database.

## TLS certificates

The HTTPS and FTPS services use certificates stored in `.cert/`.

Create the directory:

```bash
mkdir -p .cert
```

The following files are required:

```text
.cert/nginx.crt
.cert/nginx.key
.cert/vsftpd.crt
.cert/vsftpd.key
```

For local development, self-signed certificates can be generated with OpenSSL:

```bash
openssl req -x509 -nodes -days 365 \
  -newkey rsa:2048 \
  -keyout .cert/nginx.key \
  -out .cert/nginx.crt \
  -subj "/CN=localhost"

cp .cert/nginx.crt .cert/vsftpd.crt
cp .cert/nginx.key .cert/vsftpd.key
```

For production, replace these files with certificates issued for the actual domain. Ensure that the private key files are readable by Docker but are not committed to the repository.

## Host data directories

The Compose file uses bind-mounted host directories under `$HOME/data`. Create them before starting the stack:

```bash
mkdir -p \
  "$HOME/data/mariadb" \
  "$HOME/data/wordpress" \
  "$HOME/data/logs" \
  "$HOME/data/kuma_db" \
  "$HOME/data/ftp"
```

The directories must be writable by the Docker daemon and by the processes running inside the relevant containers.

The Compose file also references the following project directories:

```bash
mkdir -p adminer/frontend nginx/static
```

## Building and starting the project

Review the available Makefile targets:

```bash
make help
```

If the Makefile does not provide a help target, inspect it directly:

```bash
cat Makefile
```

A typical first-time setup is:

```bash
make
```

or, if explicit targets are provided:

```bash
make build
make up
```

The equivalent Docker Compose commands are:

```bash
docker compose build
docker compose up -d
```

To build the images and start all services in one command:

```bash
docker compose up -d --build
```

Check the status of the containers:

```bash
docker compose ps
```

Follow the logs for all services:

```bash
docker compose logs -f
```

Follow logs for one service:

```bash
docker compose logs -f nginx
docker compose logs -f wordpress
docker compose logs -f mariadb
```

The main endpoints are:

- WordPress: `https://localhost`
- HTTP redirect or web entry point: `http://localhost`
- Kuma: `http://localhost:3001`
- Adminer: exposed through the nginx configuration
- FTP/FTPS: `localhost:21`

The exact Adminer URL depends on the nginx configuration.

## Container management

List running containers:

```bash
docker compose ps
```

Start existing containers:

```bash
docker compose start
```

Stop containers without deleting them:

```bash
docker compose stop
```

Restart the entire stack:

```bash
docker compose restart
```

Restart one service:

```bash
docker compose restart wordpress
```

Stop and remove the containers and Compose network:

```bash
docker compose down
```

Stop and remove containers, networks, and anonymous volumes:

```bash
docker compose down -v
```

Use `docker compose down -v` carefully. Named volumes that are removed by this command may contain database or application data.

Execute a shell inside a running container:

```bash
docker compose exec nginx sh
docker compose exec wordpress sh
docker compose exec mariadb sh
```

If Bash is available in the image:

```bash
docker compose exec wordpress bash
```

View resource usage:

```bash
docker stats
```

## Rebuilding images

Rebuild all images after changing a Dockerfile:

```bash
docker compose build --no-cache
```

Rebuild and recreate the affected containers:

```bash
docker compose up -d --build
```

Rebuild only one service:

```bash
docker compose build wordpress
docker compose up -d wordpress
```

Remove unused Docker resources:

```bash
docker system prune
```

This command removes unused containers, networks, images, and build cache. Do not use the `--volumes` option unless you intentionally want to delete unused volumes.

## Volumes and data persistence

The project stores persistent data on the host rather than inside disposable container filesystems.

| Compose volume | Host path | Container path | Contents |
|---|---|---|---|
| `db` | `$HOME/data/mariadb` | `/var/lib/mysql` | WordPress MariaDB data |
| `wordpress_data` | `$HOME/data/wordpress` | `/srv/www/wordpress` | WordPress files and uploads |
| `adminer_page` | `$PWD/adminer/frontend` | `/var/www/adminer/` | Adminer frontend files |
| `static_pages` | `$PWD/nginx/static` | `/srv/www/wordpress/static` | Static website files |
| `logs` | `$HOME/data/logs` | `/var/log/nginx` or `/var/logs/mariadb` | Nginx and MariaDB logs |
| `kuma_data` | `$HOME/data/kuma_db` | `/var/lib/mysql` | Kuma MariaDB data |
| `postgres_gitea` | `$HOME/data/postgres_gitea` | Not currently mounted | Reserved for future Gitea/PostgreSQL use |

The FTP service uses a direct bind mount rather than a named Compose volume:

```text
$HOME/data/ftp:/srv/ftp
```

FTP files are therefore stored in:

```bash
$HOME/data/ftp
```

The `static_pages` volume is mounted read-only in nginx:

```yaml
o: bind, ro
```

Update static files on the host under `nginx/static/`; nginx can then serve them without allowing the container to modify the source directory.

Because the database, WordPress files, FTP files, Kuma database, and logs are stored in host directories, they persist when containers are stopped, recreated, or rebuilt.

## Inspecting volumes

List Docker volumes:

```bash
docker volume ls
```

Inspect a specific volume:

```bash
docker volume inspect db
docker volume inspect wordpress_data
docker volume inspect kuma_data
```

Because these volumes use bind mounts, the authoritative data is located in the host directories shown in the table above.

To back up the project data, stop the services first and archive the host directories:

```bash
docker compose stop

tar -czf wordpress-backup.tar.gz \
  "$HOME/data/wordpress" \
  "$HOME/data/mariadb" \
  "$HOME/data/kuma_db" \
  "$HOME/data/ftp"
```

Logs can be backed up separately:

```bash
tar -czf logs-backup.tar.gz "$HOME/data/logs"
```

## Troubleshooting

Check service status:

```bash
docker compose ps
```

Inspect recent logs:

```bash
docker compose logs --tail=100 nginx
docker compose logs --tail=100 wordpress
docker compose logs --tail=100 mariadb
```

Validate the Compose configuration:

```bash
docker compose config
```

Check whether required ports are already in use:

```bash
ss -tulpn | grep -E ':(21|80|443|3001)\b'
```

If a container repeatedly exits, inspect its logs and verify:

- The required `.env` variables exist.
- TLS certificate and key files exist under `.cert/`.
- The host data directories exist.
- The host data directories have suitable permissions.
- The required ports are available.
- The database credentials match the credentials expected by the WordPress and database images.

To recreate a single service while preserving persistent data:

```bash
docker compose up -d --force-recreate wordpress
```

Do not delete the database directories when troubleshooting unless the database can be safely reinitialized or has been backed up.
