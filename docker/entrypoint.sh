#!/bin/bash

## start postgresql
rm -rf /var/lib/pgsql/data/postmaster.pid
sudo -u postgres pg_ctl start -D /var/lib/pgsql/data/ > /dev/null 2>&1 &

echo "Starting Galaxy Tool Generator..."
sleep 10

echo "Clearing cache"
drush cc all &

## start apache
rm -f /usr/local/apache2/logs/httpd.pid
/usr/sbin/httpd -DFOREGROUND

# pull GTG modules updates
#cd /var/www/html/sites/all/modules/GTG_modules/galaxy_tool_generator_ui && git pull origin master
#cd /var/www/html/sites/all/modules/GTG_modules/galaxy_tool_generator && git pull origin master
#cd /var/www/html && drush en -y galaxy_tool_generator galaxy_tool_generator_ui
