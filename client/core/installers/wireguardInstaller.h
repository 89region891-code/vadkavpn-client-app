#ifndef WIREGUARDINSTALLER_H
#define WIREGUARDINSTALLER_H

#include "installerBase.h"

class WireguardInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit WireguardInstaller(QObject *parent = nullptr);

    ВадькаVPN::ErrorCode extractConfigFromContainer(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials,
                                         SshSession* serverController, ВадькаVPN::ContainerConfig &config) override;
};

#endif // WIREGUARDINSTALLER_H

