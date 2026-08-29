#ifndef CONFIGURATORBASE_H
#define CONFIGURATORBASE_H

#include <QObject>
#include <QScopedPointer>

#include "core/utils/containerEnum.h"
#include "core/utils/containers/containerUtils.h"
#include "core/utils/protocolEnum.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"
#include "core/models/containerConfig.h"
#include "core/models/protocolConfig.h"

class SshSession;

class ConfiguratorBase : public QObject
{
    Q_OBJECT
public:
    explicit ConfiguratorBase(SshSession* sshSession, QObject *parent = nullptr);

    static QScopedPointer<ConfiguratorBase> create(ВадькаVPN::Proto protocol,
                                                   SshSession* sshSession);

    virtual ВадькаVPN::ProtocolConfig createConfig(const ВадькаVPN::ServerCredentials &credentials, ВадькаVPN::DockerContainer container,
                                        const ВадькаVPN::ContainerConfig &containerConfig,
                                        const ВадькаVPN::DnsSettings &dnsSettings,
                                        ВадькаVPN::ErrorCode &errorCode) = 0;

    virtual ВадькаVPN::ProtocolConfig processConfigWithLocalSettings(const ВадькаVPN::ConnectionSettings &settings,
                                                                   ВадькаVPN::ProtocolConfig protocolConfig);
    virtual ВадькаVPN::ProtocolConfig processConfigWithExportSettings(const ВадькаVPN::ExportSettings &settings,
                                                                     ВадькаVPN::ProtocolConfig protocolConfig);

protected:
    void applyDnsToNativeConfig(const ВадькаVPN::DnsSettings &dns, ВадькаVPN::ProtocolConfig &protocolConfig);

    SshSession* m_sshSession;
};

#endif // CONFIGURATORBASE_H
