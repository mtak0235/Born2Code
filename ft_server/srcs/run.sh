#!/bin/bash

# 권한설정
chmod 775 /run.sh
chown -R www-data:www-data /var/www/
chmod -R 755 /var/www/

# ssl 개인키 및 인증서 생성
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Tak/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# nginx 설정
cp -rp /tmp/default /etc/nginx/sites-available/

# wordpress 설치 및 설정
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./tmp/wp-config.php /var/www/html/wordpress

# wordpress를 위한 DB 테이블 생성 
service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" \
	| mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'mtak'@'localhost' IDENTIFIED BY 'mtak';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'mtak'@'localhost' WITH GRANT OPTION;" \
	| mysql -u root --skip-password
	
# phpMyAdmin 설치 및 설정
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
rm phpMyAdmin-5.0.2-all-languages.tar.gz
cp -rp /tmp/config.inc.php /var/www/html/phpmyadmin/
chown -R www-data:www-data /var/www/html/phpmyadmin
chmod -R 707 /var/www/html/phpmyadmin/
chmod 705 /var/www/html/phpmyadmin/config.inc.php

#set AutoIndex
if [ "$AUTOINDEX" == "off" ];then
		sed -i "s/autoindex on/#autoindex on/" /etc/nginx/sites-available/default
fi

service nginx start
service php7.3-fpm start
service mysql reload
service mysql restart

bash