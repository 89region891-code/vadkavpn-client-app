#ifndef DNSPROTOCOLCONFIG_H
#define DNSPROTOCOLCONFIG_H

#include <QJsonObject>

namespace ВадькаVPN
{

struct DnsProtocolConfig {
    QJsonObject toJson() const;
    static DnsProtocolConfig fromJson(const QJsonObject& json);
};

} // namespace ВадькаVPN

#endif // DNSPROTOCOLCONFIG_H

