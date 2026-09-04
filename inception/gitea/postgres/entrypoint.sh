#!/bin/bash

chown -R postgres: /srv/postgres

su postgres

postgres /etc/postgres/postgresql.conf
# Create the role if it does not already exist
psql -v ON_ERROR_STOP=1 <<SQL
DO \$\$
BEGIN
    IF NOT EXISTS (
        SELECT FROM pg_catalog.pg_roles
        WHERE rolname = '${DB_USER}'
    ) THEN
        CREATE ROLE ${DB_USER} LOGIN PASSWORD '${DB_PASSWORD}';
    ELSE
        ALTER ROLE ${DB_USER} WITH LOGIN PASSWORD '${DB_PASSWORD}';
    END IF;
END
\$\$;
SQL

# CREATE DATABASE cannot run inside a DO block or transaction
if ! psql -tAc "SELECT 1 FROM pg_database WHERE datname = '${DB_NAME}'" | grep -q 1; then
    createdb \
        --host="$PGHOST" \
        --port="$PGPORT" \
        --username="$PGUSER" \
        "$DB_NAME"
fi

# Make the user the database owner
psql -v ON_ERROR_STOP=1 <<SQL
ALTER DATABASE ${DB_NAME} OWNER TO ${DB_USER};
SQL

echo "PostgreSQL initialization completed."

sleep 99999999
