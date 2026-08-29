#ifndef SWIFTBRIDGE_H
#define SWIFTBRIDGE_H

#if defined(Q_OS_IOS) || defined(MACOS_NE)
#include "core/utils/swiftBridgeConfig.h"

#ifndef SWIFT_BRIDGE_OBJC_HEADER
#ifdef ВадькаVPN_SWIFT_OBJC_HEADER
#define SWIFT_BRIDGE_OBJC_HEADER ВадькаVPN_SWIFT_OBJC_HEADER
#else
#define SWIFT_BRIDGE_OBJC_HEADER "ВадькаVPNVPN-Swift.h"
#endif
#endif
#ifndef SWIFT_BRIDGE_NAMESPACE
#ifdef ВадькаVPN_SWIFT_NAMESPACE
#define SWIFT_BRIDGE_NAMESPACE ВадькаVPN_SWIFT_NAMESPACE
#else
#define SWIFT_BRIDGE_NAMESPACE ВадькаVPNVPN
#endif
#endif

#include SWIFT_BRIDGE_OBJC_HEADER
#endif

#endif
