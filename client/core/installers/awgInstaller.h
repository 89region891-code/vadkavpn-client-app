#ifndef AWGINSTALLER_H
#define AWGINSTALLER_H

#include "installerBase.h"

class AwgInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit AwgInstaller(QObject *parent = nullptr);

    ВадькаVPN::ContainerConfig generateConfig(ВадькаVPN::DockerContainer container, int port, ВадькаVPN::TransportProto transportProto) override;
    ВадькаVPN::ErrorCode extractConfigFromContainer(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials,
                                         SshSession* serverController, ВадькаVPN::ContainerConfig &config) override;

private:
    void generateAwgParameters(ВадькаVPN::AwgServerConfig &serverConfig);
};

#endif // AWGINSTALLER_H

