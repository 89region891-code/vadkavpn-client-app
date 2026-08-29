#ifndef INSTALLERBASE_H
#define INSTALLERBASE_H

#include <QObject>
#include <QJsonObject>

#include "core/utils/containerEnum.h"
#include "core/utils/protocolEnum.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"
#include "core/utils/selfhosted/sshSession.h"
#include "core/models/containerConfig.h"

class InstallerBase : public QObject
{
    Q_OBJECT
public:
    explicit InstallerBase(QObject *parent = nullptr);

    virtual ВадькаVPN::ContainerConfig generateConfig(ВадькаVPN::DockerContainer container, int port, ВадькаVPN::TransportProto transportProto);

    virtual ВадькаVPN::ErrorCode extractConfigFromContainer(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials,
                                                 SshSession* sshSession, ВадькаVPN::ContainerConfig &config);

    ВадькаVPN::ContainerConfig createBaseConfig(ВадькаVPN::DockerContainer container, int port, ВадькаVPN::TransportProto transportProto);

protected:
};

#endif // INSTALLERBASE_H

