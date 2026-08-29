#ifndef WIREGUARD_CONFIGURATOR_H
#define WIREGUARD_CONFIGURATOR_H

#include <QHostAddress>
#include <QObject>
#include <QProcessEnvironment>

#include "configuratorBase.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"
#include "core/utils/selfhosted/scriptsRegistry.h"

class WireguardConfigurator : public ConfiguratorBase
{
    Q_OBJECT
public:
    WireguardConfigurator(SshSession* sshSession,
                          bool isAwg, QObject *parent = nullptr);

    struct ConnectionData
    {
        QString clientPrivKey; // client private key
        QString clientPubKey;  // client public key
        QString clientIP;      // internal client IP address
        QString serverPubKey;  // tls-auth key
        QString pskKey;        // preshared key
        QString host;          // host ip
        QString port;
    };

    ВадькаVPN::ProtocolConfig createConfig(const ВадькаVPN::ServerCredentials &credentials, ВадькаVPN::DockerContainer container,
                                const ВадькаVPN::ContainerConfig &containerConfig,
                                const ВадькаVPN::DnsSettings &dnsSettings,
                                ВадькаVPN::ErrorCode &errorCode) override;

    ВадькаVPN::ProtocolConfig processConfigWithLocalSettings(const ВадькаVPN::ConnectionSettings &settings,
                                                           ВадькаVPN::ProtocolConfig protocolConfig) override;
    ВадькаVPN::ProtocolConfig processConfigWithExportSettings(const ВадькаVPN::ExportSettings &settings,
                                                            ВадькаVPN::ProtocolConfig protocolConfig) override;

    static ConnectionData genClientKeys();

private:
    QList<QHostAddress> getIpsFromConf(const QString &input);
    ConnectionData prepareWireguardConfig(const ВадькаVPN::ServerCredentials &credentials, ВадькаVPN::DockerContainer container,
                                          const ВадькаVPN::WireGuardServerConfig* serverConfig,
                                          const ВадькаVPN::AwgServerConfig* awgServerConfig,
                                          const ВадькаVPN::DnsSettings &dnsSettings,
                                          ВадькаVPN::ErrorCode &errorCode);

    bool m_isAwg;
    QString m_serverConfigPath;
    QString m_serverPublicKeyPath;
    QString m_serverPskKeyPath;
    ВадькаVPN::ProtocolScriptType m_configTemplate;
    QString m_protocolName;
    QString m_defaultPort;
};

#endif // WIREGUARD_CONFIGURATOR_H
