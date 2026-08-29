#ifndef SFTPPROTOCOLCONFIG_H
#define SFTPPROTOCOLCONFIG_H

#include <QJsonObject>
#include <QString>

namespace ВадькаVPN
{

struct SftpProtocolConfig {
    QString port;
    QString userName;
    QString password;
    
    QJsonObject toJson() const;
    static SftpProtocolConfig fromJson(const QJsonObject& json);
};

} // namespace ВадькаVPN

#endif // SFTPPROTOCOLCONFIG_H

