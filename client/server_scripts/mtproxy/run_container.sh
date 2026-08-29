# Run container
sudo docker run -d \
  --log-driver none \
  --restart always \
  -p $MTPROXY_PORT:$MTPROXY_PORT/tcp \
  -v ВадькаVPN-mtproxy-data:/data \
  --name $CONTAINER_NAME \
  $CONTAINER_NAME

