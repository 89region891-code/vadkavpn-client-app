FROM ВадькаVPNvpn/mtproxy:latest

RUN mkdir -p /opt/ВадькаVPN /data
RUN printf '#!/bin/sh\ntail -f /dev/null\n' > /opt/ВадькаVPN/start.sh && \
    chmod a+x /opt/ВадькаVPN/start.sh

VOLUME /data
ENTRYPOINT ["/bin/sh", "/opt/ВадькаVPN/start.sh"]
CMD [""]
