<div align=center>
	<h1>USER DOCUMENTATION</h1>
</div>

## About the project

This project provides a WordPress website and several supporting services running in Docker containers.

The stack includes:

- **WordPress** — website content management system
- **Nginx** — web server and HTTPS entry point
- **MariaDB** — database used by WordPress
- **Adminer** — web-based database administration tool
- **FTP/FTPS** — file transfer service for managing website files
- **Redis** — caching service for WordPress
- **Kuma** — service monitoring dashboard
- **Kuma MariaDB** — database used by Kuma

The main website is accessed through nginx. Other services are available only through their configured ports or nginx routes.

## Starting the project

Open a terminal in the project directory and start the complete stack:

```bash
make
```

If the Makefile provides an explicit start target, use:

```bash
make up
```

The equivalent Docker Compose command is:

```bash
docker compose up -d
```

To build the images before starting the services:

```bash
docker compose up -d --build
```

The `-d` option starts the services in the background.

Check the current status:

```bash
docker compose ps
```

All required services should show a status similar to:

```text
Up
```

## Stopping the project

To stop the running containers without deleting them:

```bash
docker compose stop
```

The project can be started again later with:

```bash
docker compose start
```

To stop and remove the containers and the Compose network:

```bash
docker compose down
```

This does not remove the persistent application data stored in the host directories.

Do not use the following command unless you intentionally want to remove Docker volumes:

```bash
docker compose down -v
```

Removing volumes may permanently delete databases or other stored data.

## Accessing the website

Open the website in a browser:

```text
https://localhost
```

The project also exposes HTTP on:

```text
http://localhost
```

The nginx configuration may redirect HTTP requests to HTTPS.

If self-signed certificates are being used for local development, the browser may display a certificate warning. This is expected for locally generated certificates. For production use, the site should use a certificate issued for the configured domain.

## Accessing the WordPress administration panel

The WordPress administration panel is available at:

```text
https://localhost/wp-admin/
```

If WordPress asks for a login page, use the administrator account created during the WordPress setup.

The administration panel allows administrators to:

- Create and edit pages and posts
- Upload media
- Manage themes and plugins
- Create and manage users
- Change website settings
- View and moderate comments

If `/wp-admin/` does not load, try:

```text
https://localhost/wp-login.php
```

## Accessing Adminer

Adminer is a web interface for managing the WordPress MariaDB database.

The URL depends on the nginx routing configuration. The expected address is commonly:

```text
https://localhost/adminer/
```

If that route is not configured, Adminer may not be directly accessible through the browser. An administrator can verify the nginx configuration or inspect the running services:

```bash
docker compose ps
docker compose logs nginx
```

When signing in to Adminer, use:

| Field | Value |
|---|---|
| System | MySQL or MariaDB |
| Server | `mariadb` |
| Username | Value of `MARIADB_USERNAME` |
| Password | Value of `MARIADB_PASSWORD` |
| Database | The WordPress database configured by the database image |

The database server name is `mariadb` because Adminer connects to MariaDB through the Docker network. Do not use `localhost` from inside the Adminer container.

## Accessing Kuma

Kuma is available on port `3001`:

```text
http://localhost:3001
```

Kuma is used to monitor the availability of project services.

The Kuma database is stored separately from the WordPress database. Its credentials are configured using:

- `KUMA_USERNAME`
- `KUMA_PASSWORD`
- `KUMA_ROOT_PASSWORD`

## FTP access

The FTP service listens on port `21` and uses passive ports `40000` through `40100`.

Use the following connection details:

| Setting | Value |
|---|---|
| Host | Server IP address or hostname |
| Port | `21` |
| Protocol | FTP or FTPS, depending on client configuration |
| Username | FTP user configured by the image |
| Password | Value of `FTP_PASSWORD` |
| Passive ports | `40000-40100` |

When TLS is enabled, configure the FTP client to use explicit or implicit FTPS according to the `vsftpd` configuration.

Uploaded files are stored on the host in:

```text
$HOME/data/ftp
```

Use FTP carefully. Changing or deleting WordPress files can make the website unavailable.

## Locating credentials

Credentials are configured in the `.env` file located in the project root:

```text
.env
```

The file contains values similar to:

```dotenv
MARIADB_USERNAME=wordpress
MARIADB_PASSWORD=change-this-password
MARIADB_ROOT_PASSWORD=change-this-root-password
FTP_PASSWORD=change-this-ftp-password
KUMA_USERNAME=kuma
KUMA_PASSWORD=change-this-kuma-password
KUMA_ROOT_PASSWORD=change-this-kuma-root-password
```

The `.env` file should only be readable by authorized administrators. It must not be uploaded to a public repository or shared publicly.

Restrict access to the file on Linux:

```bash
chmod 600 .env
```

TLS private keys are stored in:

```text
.cert/nginx.key
.cert/vsftpd.key
```

These files are also sensitive and must not be shared publicly.

The WordPress administrator password is created during the WordPress installation process. It may not be stored in `.env`. If the administrator password is lost, reset it through an authorized WordPress or database administration procedure.

## Checking that the services are running

Display the status of all services:

```bash
docker compose ps
```

The mandatory services should be running:

- `nginx`
- `wordpress`
- `mariadb`

If the optional services are enabled, these should also be running:

- `ftp`
- `adminer`
- `redis`
- `kuma`
- `kuma-mariadb`

View recent logs for the entire stack:

```bash
docker compose logs --tail=100
```

Follow logs while testing the application:

```bash
docker compose logs -f
```

View logs for a specific service:

```bash
docker compose logs -f nginx
docker compose logs -f wordpress
docker compose logs -f mariadb
docker compose logs -f kuma
```

A basic service check can be performed as follows:

1. Open `https://localhost` and confirm that the website loads.
2. Open `https://localhost/wp-admin/` and confirm that the WordPress login page appears.
3. Open the Adminer route and confirm that the login page loads.
4. Open `http://localhost:3001` and confirm that Kuma is available.
5. Run `docker compose ps` and confirm that the containers remain running.
6. Check the logs for repeated errors or container restarts.

A container with a status such as `Restarting` or `Exited` requires investigation:

```bash
docker compose logs --tail=100 SERVICE_NAME
```

Replace `SERVICE_NAME` with the affected service, for example:

```bash
docker compose logs --tail=100 wordpress
```

## Managing persistent data

Project data is stored on the host and remains available when containers are stopped or recreated.

Important locations include:

```text
$HOME/data/wordpress   WordPress files and uploads
$HOME/data/mariadb     WordPress database
$HOME/data/kuma_db      Kuma database
$HOME/data/ftp          FTP files
$HOME/data/logs         Service logs
```

Do not delete these directories unless the corresponding data is no longer needed or a backup has been created.

Before making major changes, stop the project and create a backup:

```bash
docker compose stop

tar -czf project-backup.tar.gz \
  "$HOME/data/wordpress" \
  "$HOME/data/mariadb" \
  "$HOME/data/kuma_db" \
  "$HOME/data/ftp"
```

Restore procedures should be performed by an administrator and should preserve the original directory ownership and permissions.
