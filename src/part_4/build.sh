#!/bin/bash


gcc -o main /home/back.c -lfcgi
spawn-fcgi -p 8080 -f /home/main

/bin/bash