#ifndef XRAYINSTALLER_H
#define XRAYINSTALLER_H

#include "installerBase.h"

class XrayInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit XrayInstaller(QObject *parent = nullptr);

    ВадькаVPN::ErrorCode extractConfigFromContainer(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials,
                                         SshSession* serverController, ВадькаVPN::ContainerConfig &config) override;
};

#endif // XRAYINSTALLER_H

