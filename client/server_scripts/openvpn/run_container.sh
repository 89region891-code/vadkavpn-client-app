# Run container
sudo docker run -d \
--privileged \
--log-driver none \
--restart always \
--cap-add=NET_ADMIN \
-p $OPENVPN_PORT:$OPENVPN_PORT/$OPENVPN_TRANSPORT_PROTO \
--name $CONTAINER_NAME $CONTAINER_NAME

sudo docker network connect ВадькаVPN-dns-net $CONTAINER_NAME

# Create tun device if not exist
sudo docker exec -i $CONTAINER_NAME bash -c 'mkdir -p /dev/net; if [ ! -c /dev/net/tun ]; then mknod /dev/net/tun c 10 200; fi'

# Prevent to route packets outside of the container in case if server behind of the NAT
sudo docker exec -i $CONTAINER_NAME sh -c "ifconfig eth0:0 $SERVER_IP_ADDRESS netmask 255.255.255.255 up"

# OpenVPN config
sudo docker exec -i $CONTAINER_NAME bash -c 'mkdir -p /opt/ВадькаVPN/openvpn/clients; \
cd /opt/ВадькаVPN/openvpn && easyrsa init-pki; \
cd /opt/ВадькаVPN/openvpn && easyrsa gen-dh; \
cd /opt/ВадькаVPN/openvpn && cp pki/dh.pem /opt/ВадькаVPN/openvpn && easyrsa build-ca nopass << EOF yes EOF && easyrsa gen-req ВадькаVPNReq nopass << EOF2 yes EOF2;\
cd /opt/ВадькаVPN/openvpn && easyrsa sign-req server ВадькаVPNReq << EOF3 yes EOF3;\
cd /opt/ВадькаVPN/openvpn && openvpn --genkey --secret ta.key << EOF4;\
cd /opt/ВадькаVPN/openvpn && cp pki/ca.crt pki/issued/ВадькаVPNReq.crt pki/private/ВадькаVPNReq.key /opt/ВадькаVPN/openvpn;\
cd /opt/ВадькаVPN/openvpn && easyrsa gen-crl;\
cd /opt/ВадькаVPN/openvpn && cp pki/crl.pem /opt/ВадькаVPN/openvpn/crl.pem'
