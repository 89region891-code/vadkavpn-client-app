#ifndef SERVERCONFIGUTILS_H
#define SERVERCONFIGUTILS_H

#include <QJsonObject>

namespace serverConfigUtils
{

enum ConfigType {
    ВадькаVPNFreeV2 = 0,
    ВадькаVPNFreeV3,
    ВадькаVPNPremiumV1,
    ВадькаVPNPremiumV2,
    SelfHosted,
    ExternalPremium,

    SelfHostedAdmin = 8,
    SelfHostedUser,
    Native,
    Invalid
};

enum ConfigSource {
    Telegram = 1,
    ВадькаVPNGateway
};

bool isServerFromApi(const QJsonObject &serverConfigObject);

ConfigSource getConfigSource(const QJsonObject &serverConfigObject);

ConfigType configTypeFromJson(const QJsonObject &serverConfigObject);

bool isLegacyApiSubscription(ConfigType configType);

bool isApiV2Subscription(ConfigType configType);

} // namespace serverConfigUtils

#endif // SERVERCONFIGUTILS_H
