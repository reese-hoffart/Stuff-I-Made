# sudo docker build -t imbufferthanyoutoo .
# sudo docker run -d -p 64501:64501 --rm -it imbufferthanyoutoo

FROM ubuntu:19.10

RUN apt-get update

RUN useradd -d /home/ctf/ -m -p ctf -s /bin/bash ctf
RUN echo "ctf:ctf" | chpasswd

WORKDIR /home/ctf

COPY imbufferthanyoutoo .
COPY flag.txt .
COPY ynetd .

RUN chown -R root:root /home/ctf

USER ctf
EXPOSE 64501
CMD ./ynetd -p 64501 ./imbufferthanyoutoo
