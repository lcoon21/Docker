#!/bin/bash

apt -y update && apt -y upgrade
apt -y install libfcgi-dev spawn-fcgi nginx links
apt -y install gcc
gcc -o main back.c -lfcgi
spawn-fcgi -p 8080 ./main
cp -f nginx.conf /etc/nginx/
service nginx start