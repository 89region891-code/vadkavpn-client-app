package org.ВадькаVPN.vpn.util

// keep synchronized with client/core/utils/errorCodes.h ВадькаVPN::ErrorCode
object ErrorCode {
    const val NoError = 0

    const val BillingCanceled = 1300
    const val BillingError = 1301
    const val BillingGooglePlayError = 1302
    const val BillingUnavailable = 1303
    const val SubscriptionAlreadyOwned = 1304
    const val SubscriptionUnavailable = 1305
    const val BillingNetworkError = 1306
}
