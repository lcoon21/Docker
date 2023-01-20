FROM nginx

COPY nginx.conf /etc/nginx/
COPY build.sh /home/
COPY back.c /home/

RUN apt-get -y update \
    && apt-get -y install \
    libfcgi-dev spawn-fcgi gcc \
    && rm -rf /var/lib/apt/lists/* 
    

USER nginx

WORKDIR /home/

ENTRYPOINT (service nginx start) && (bash /home/build.sh)

HEALTHCHECK --timeout=10s CMD curl localhost:80/status
