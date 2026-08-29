sudo docker ps -a | grep ВадькаVPN | awk '{print $1}' | xargs sudo docker stop;\
sudo docker ps -a | grep ВадькаVPN | awk '{print $1}' | xargs sudo docker rm -fv;\
sudo docker images -a --format table | grep ВадькаVPN | awk '{print $3, $1 ":" $2}' | xargs sudo docker rmi;\
sudo docker volume ls --format '{{.Name}}' | grep '^ВадькаVPN-' | xargs -r sudo docker volume rm -f;\
sudo docker network ls | grep ВадькаVPN-dns-net | awk '{print $1}' | xargs sudo docker network rm;\
sudo rm -frd /opt/ВадькаVPN
