#ifndef AWGCONFIGURATOR_H
#define AWGCONFIGURATOR_H

#include <QObject>

#include "wireguardConfigurator.h"

class AwgConfigurator : public WireguardConfigurator
{
    Q_OBJECT
public:
    AwgConfigurator(SshSession* sshSession, QObject *parent = nullptr);

    ВадькаVPN::ProtocolConfig createConfig(const ВадькаVPN::ServerCredentials &credentials, ВадькаVPN::DockerContainer container,
                                const ВадькаVPN::ContainerConfig &containerConfig,
                                const ВадькаVPN::DnsSettings &dnsSettings,
                                ВадькаVPN::ErrorCode &errorCode) override;
};

#endif // AWGCONFIGURATOR_H
