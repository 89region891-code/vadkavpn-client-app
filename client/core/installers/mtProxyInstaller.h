#ifndef MTPROXYINSTALLER_H
#define MTPROXYINSTALLER_H

#include "installerBase.h"

#include <QString>

struct MtProxyContainerDiagnostics {
    bool portReachable = false;
    bool upstreamReachable = false;
    int clientsConnected = -1;
    QString lastConfigRefresh;
    QString statsEndpoint;
};

class MtProxyInstaller : public InstallerBase {
Q_OBJECT
public:
    explicit MtProxyInstaller(QObject *parent = nullptr);

    ВадькаVPN::ErrorCode
    extractConfigFromContainer(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials,
                               SshSession *sshSession, ВадькаVPN::ContainerConfig &config) override;

    static void uploadClientSettingsSnapshot(SshSession &sshSession, const ВадькаVPN::ServerCredentials &credentials,
                                             ВадькаVPN::DockerContainer container,
                                             const ВадькаVPN::ContainerConfig &config);

    static ВадькаVPN::ErrorCode queryDiagnostics(SshSession &sshSession, const ВадькаVPN::ServerCredentials &credentials,
                                               ВадькаVPN::DockerContainer container, int listenPort,
                                               MtProxyContainerDiagnostics &out);
};

#endif // MTPROXYINSTALLER_H
