#include "serverConfigUtils.h"

#include <QJsonArray>
#include <QJsonValue>

#include "core/models/selfhosted/selfHostedAdminServerConfig.h"
#include "core/utils/constants/apiKeys.h"
#include "core/utils/constants/configKeys.h"

namespace
{

bool hasThirdPartyConfig(const QJsonObject &json)
{
    const QJsonArray containersArray = json.value(ВадькаVPN::configKey::containers).toArray();
    for (const QJsonValue &val : containersArray) {
        const QJsonObject containerObj = val.toObject();
        for (auto it = containerObj.begin(); it != containerObj.end(); ++it) {
            if (it.key() == ВадькаVPN::configKey::container) {
                continue;
            }
            const QJsonObject protocolObj = it.value().toObject();
            if (protocolObj.contains(ВадькаVPN::configKey::isThirdPartyConfig)
                && protocolObj.value(ВадькаVPN::configKey::isThirdPartyConfig).toBool()) {
                return true;
            }
        }
    }
    return false;
}

} // namespace

namespace serverConfigUtils
{

bool isServerFromApi(const QJsonObject &serverConfigObject)
{
    const int configVersion = serverConfigObject.value(ВадькаVPN::configKey::configVersion).toInt();
    switch (configVersion) {
    case ConfigSource::Telegram:
    case ConfigSource::ВадькаVPNGateway:
        return true;
    default:
        return false;
    }
}

ConfigSource getConfigSource(const QJsonObject &serverConfigObject)
{
    return static_cast<ConfigSource>(serverConfigObject.value(ВадькаVPN::configKey::configVersion).toInt());
}

ConfigType configTypeFromJson(const QJsonObject &serverConfigObject)
{
    const int configVersion = serverConfigObject.value(ВадькаVPN::configKey::configVersion).toInt();

    switch (configVersion) {
    case ConfigSource::Telegram: {
        constexpr QLatin1String freeV2Endpoint(FREE_V2_ENDPOINT);
        constexpr QLatin1String premiumV1Endpoint(PREM_V1_ENDPOINT);

        const QString apiEndpointValue = serverConfigObject.value(apiDefs::key::apiEndpoint).toString();

        if (apiEndpointValue.contains(premiumV1Endpoint)) {
            return ConfigType::ВадькаVPNPremiumV1;
        }
        if (apiEndpointValue.contains(freeV2Endpoint)) {
            return ConfigType::ВадькаVPNFreeV2;
        }
    }
        [[fallthrough]];
    case ConfigSource::ВадькаVPNGateway: {
        constexpr QLatin1String servicePremium("ВадькаVPN-premium");
        constexpr QLatin1String serviceFree("ВадькаVPN-free");
        constexpr QLatin1String serviceExternalPremium("external-premium");

        const QJsonObject apiConfigObject = serverConfigObject.value(apiDefs::key::apiConfig).toObject();
        const QString serviceTypeStr = apiConfigObject.value(apiDefs::key::serviceType).toString();

        if (serviceTypeStr == servicePremium) {
            return ConfigType::ВадькаVPNPremiumV2;
        }
        if (serviceTypeStr == serviceFree) {
            return ConfigType::ВадькаVPNFreeV3;
        }
        if (serviceTypeStr == serviceExternalPremium) {
            return ConfigType::ExternalPremium;
        }
        break;
    }
    default:
        break;
    }

    if (hasThirdPartyConfig(serverConfigObject)) {
        return ConfigType::Native;
    }

    const ВадькаVPN::SelfHostedAdminServerConfig adminProbe =
            ВадькаVPN::SelfHostedAdminServerConfig::fromJson(serverConfigObject);
    return adminProbe.hasCredentials() ? ConfigType::SelfHostedAdmin : ConfigType::SelfHostedUser;
}

bool isLegacyApiSubscription(ConfigType configType)
{
    return configType == ConfigType::ВадькаVPNPremiumV1 || configType == ConfigType::ВадькаVPNFreeV2;
}

bool isApiV2Subscription(ConfigType configType)
{
    switch (configType) {
    case ConfigType::ВадькаVPNPremiumV2:
    case ConfigType::ВадькаVPNFreeV3:
    case ConfigType::ExternalPremium:
        return true;
    default:
        return false;
    }
}

} // namespace serverConfigUtils
