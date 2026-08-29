#ifndef TELEMTINSTALLER_H
#define TELEMTINSTALLER_H

#include "installerBase.h"

class TelemtInstaller : public InstallerBase {
Q_OBJECT
public:
    explicit TelemtInstaller(QObject *parent = nullptr);

    ВадькаVPN::ErrorCode
    extractConfigFromContainer(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials,
                               SshSession *sshSession, ВадькаVPN::ContainerConfig &config) override;

    static void uploadClientSettingsSnapshot(SshSession &sshSession, const ВадькаVPN::ServerCredentials &credentials,
                                             ВадькаVPN::DockerContainer container,
                                             const ВадькаVPN::ContainerConfig &config);
};

#endif // TELEMTINSTALLER_H
