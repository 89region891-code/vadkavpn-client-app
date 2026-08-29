#ifndef XRAY_CONFIGURATOR_H
#define XRAY_CONFIGURATOR_H

#include <QObject>
#include <QJsonObject>

#include "configuratorBase.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"
#include "core/models/protocols/xrayProtocolConfig.h"

class XrayConfigurator : public ConfiguratorBase
{
    Q_OBJECT
public:
    XrayConfigurator(SshSession* sshSession, QObject *parent = nullptr);

    ВадькаVPN::ProtocolConfig createConfig(const ВадькаVPN::ServerCredentials &credentials, ВадькаVPN::DockerContainer container, const ВадькаVPN::ContainerConfig &containerConfig,
                                const ВадькаVPN::DnsSettings &dnsSettings,
                                ВадькаVPN::ErrorCode &errorCode) override;

    ВадькаVPN::ProtocolConfig processConfigWithLocalSettings(const ВадькаVPN::ConnectionSettings &settings,
                                                           ВадькаVPN::ProtocolConfig protocolConfig) override;

    ВадькаVPN::ErrorCode applyServerSettingsToRemote(const ВадькаVPN::ServerCredentials &credentials,
                                                   ВадькаVPN::DockerContainer container,
                                                   ВадькаVPN::ContainerConfig &containerConfig,
                                                   const ВадькаVPN::DnsSettings &dnsSettings,
                                                   bool appendNewClient,
                                                   QString *outClientId = nullptr);

    ВадькаVPN::ErrorCode writeServerConfigForSetup(const ВадькаVPN::ServerCredentials &credentials,
                                                 ВадькаVPN::DockerContainer container,
                                                 ВадькаVPN::ContainerConfig &containerConfig,
                                                 const ВадькаVPN::DnsSettings &dnsSettings);

private:
    ВадькаVPN::ErrorCode readContainerKeyFile(ВадькаVPN::DockerContainer container,
                                            const ВадькаVPN::ServerCredentials &credentials,
                                            const QString &path, QString &out) const;

    QString prepareServerConfig(const ВадькаVPN::ServerCredentials &credentials, ВадькаVPN::DockerContainer container, const ВадькаVPN::ContainerConfig &containerConfig,
                                const ВадькаVPN::DnsSettings &dnsSettings,
                                ВадькаVPN::ErrorCode &errorCode);

    ВадькаVPN::ErrorCode uploadServerConfigJson(const ВадькаVPN::ServerCredentials &credentials, ВадькаVPN::DockerContainer container,
                                              const ВадькаVPN::DnsSettings &dnsSettings, const QJsonObject &serverConfig) const;

    ВадькаVPN::XrayProtocolConfig buildClientProtocolConfig(const ВадькаVPN::ServerCredentials &credentials,
                                                          ВадькаVPN::DockerContainer container,
                                                          const ВадькаVPN::XrayServerConfig &srv,
                                                          const QString &clientId,
                                                          ВадькаVPN::ErrorCode &errorCode,
                                                          const QString &prefetchedRealityPublicKey = {},
                                                          const QString &prefetchedRealityShortId = {}) const;

    ВадькаVPN::ErrorCode readRealityKeyFiles(ВадькаVPN::DockerContainer container,
                                           const ВадькаVPN::ServerCredentials &credentials,
                                           QString &outPublicKey,
                                           QString &outShortId) const;

    QJsonObject buildStreamSettings(const ВадькаVPN::XrayServerConfig &srv,
                                    const QString &clientId) const;
};

#endif // XRAY_CONFIGURATOR_H
