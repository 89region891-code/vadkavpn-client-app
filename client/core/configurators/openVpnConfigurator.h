#ifndef OPENVPN_CONFIGURATOR_H
#define OPENVPN_CONFIGURATOR_H

#include <QObject>
#include <QProcessEnvironment>

#include "configuratorBase.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"

class OpenVpnConfigurator : public ConfiguratorBase
{
    Q_OBJECT
public:
    OpenVpnConfigurator(SshSession* sshSession, QObject *parent = nullptr);

    struct ConnectionData
    {
        QString clientId;
        QString request;    // certificate request
        QString privKey;    // client private key
        QString clientCert; // client signed certificate
        QString caCert;     // server certificate
        QString taKey;      // tls-auth key
        QString host;       // host ip
    };

    ВадькаVPN::ProtocolConfig createConfig(const ВадькаVPN::ServerCredentials &credentials, ВадькаVPN::DockerContainer container,
                               const ВадькаVPN::ContainerConfig &containerConfig,
                               const ВадькаVPN::DnsSettings &dnsSettings,
                               ВадькаVPN::ErrorCode &errorCode) override;

    ВадькаVPN::ProtocolConfig processConfigWithLocalSettings(const ВадькаVPN::ConnectionSettings &settings,
                                                           ВадькаVPN::ProtocolConfig protocolConfig) override;
    ВадькаVPN::ProtocolConfig processConfigWithExportSettings(const ВадькаVPN::ExportSettings &settings,
                                                            ВадькаVPN::ProtocolConfig protocolConfig) override;

    static ConnectionData createCertRequest();

private:
    ConnectionData prepareOpenVpnConfig(const ВадькаVPN::ServerCredentials &credentials, ВадькаVPN::DockerContainer container,
                                       const ВадькаVPN::DnsSettings &dnsSettings,
                                       ВадькаVPN::ErrorCode &errorCode);
    ВадькаVPN::ErrorCode signCert(ВадькаVPN::DockerContainer container, const ВадькаVPN::ServerCredentials &credentials, 
                      const ВадькаVPN::DnsSettings &dnsSettings, QString clientId);
};

#endif // OPENVPN_CONFIGURATOR_H
