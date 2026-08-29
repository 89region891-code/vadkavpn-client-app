#!/bin/sh

# This scripts copied from ВадькаVPN client to Docker container to /opt/ВадькаVPN and launched every time container starts

echo "Container startup"

/bin/3proxy /usr/local/3proxy/conf/3proxy.cfg