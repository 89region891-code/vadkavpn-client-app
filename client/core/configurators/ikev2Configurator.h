#ifndef IKEV2_CONFIGURATOR_H
#define IKEV2_CONFIGURATOR_H

#include <QObject>
#include <QProcessEnvironment>

#include "configuratorBase.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"

class Ikev2Configurator : public ConfiguratorBase
{
    Q_OBJECT
public:
    Ikev2Configurator(SshSession* sshSession, QObject *parent = nullptr);

    struct ConnectionData {
        QByteArray clientCert; // p12 client cert
        QByteArray caCert; // p12 server cert
        QString clientId;
        QString password; // certificate password
        QString host; // host ip
    };

    ВадькаVPN::ProtocolConfig createConfig(const ВадькаVPN::ServerCredentials &credentials, ВадькаVPN::DockerContainer container,
                                const ВадькаVPN::ContainerConfig &containerConfig,
                                const ВадькаVPN::DnsSettings &dnsSettings,
                                ВадькаVPN::ErrorCode &errorCode) override;

    QString genIkev2Config(const ConnectionData &connData);
    QString genMobileConfig(const ConnectionData &connData);
    QString genStrongSwanConfig(const ConnectionData &connData);

    ConnectionData prepareIkev2Config(const ВадькаVPN::ServerCredentials &credentials,
        ВадькаVPN::DockerContainer container, ВадькаVPN::ErrorCode &errorCode);
};

#endif // IKEV2_CONFIGURATOR_H
