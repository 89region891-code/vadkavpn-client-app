#ifndef TORINSTALLER_H
#define TORINSTALLER_H

#include "installerBase.h"

class TorInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit TorInstaller(QObject *parent = nullptr);

    ВадькаVPN::ErrorCode extractConfigFromContainer(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials,
                                         SshSession* serverController, ВадькаVPN::ContainerConfig &config) override;
};

#endif // TORINSTALLER_H

