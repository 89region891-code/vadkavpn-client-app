#ifndef SOCKS5INSTALLER_H
#define SOCKS5INSTALLER_H

#include "installerBase.h"

class Socks5Installer : public InstallerBase
{
    Q_OBJECT
public:
    explicit Socks5Installer(QObject *parent = nullptr);

    ВадькаVPN::ContainerConfig generateConfig(ВадькаVPN::DockerContainer container, int port, ВадькаVPN::TransportProto transportProto) override;
    ВадькаVPN::ErrorCode extractConfigFromContainer(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials,
                                         SshSession* serverController, ВадькаVPN::ContainerConfig &config) override;
};

#endif // SOCKS5INSTALLER_H

