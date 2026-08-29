FROM 3proxy/3proxy:0.9.5

LABEL maintainer="ВадькаVPNVPN" 

RUN mkdir -p /opt/ВадькаVPN
RUN echo -e "#!/bin/bash\ntail -f /dev/null" > /opt/ВадькаVPN/start.sh
RUN chmod a+x /opt/ВадькаVPN/start.sh

ENTRYPOINT [ "/bin/sh", "/opt/ВадькаVPN/start.sh" ]
CMD [ "" ]
