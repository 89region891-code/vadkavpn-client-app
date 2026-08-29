#ifndef OPENVPNINSTALLER_H
#define OPENVPNINSTALLER_H

#include "installerBase.h"

class OpenVpnInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit OpenVpnInstaller(QObject *parent = nullptr);

    ВадькаVPN::ErrorCode extractConfigFromContainer(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials,
                                         SshSession* serverController, ВадькаVPN::ContainerConfig &config) override;
};

#endif // OPENVPNINSTALLER_H

