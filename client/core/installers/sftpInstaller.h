#ifndef SFTPINSTALLER_H
#define SFTPINSTALLER_H

#include "installerBase.h"

class SftpInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit SftpInstaller(QObject *parent = nullptr);

    ВадькаVPN::ContainerConfig generateConfig(ВадькаVPN::DockerContainer container, int port, ВадькаVPN::TransportProto transportProto) override;
    ВадькаVPN::ErrorCode extractConfigFromContainer(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials,
                                         SshSession* serverController, ВадькаVPN::ContainerConfig &config) override;
};

#endif // SFTPINSTALLER_H

