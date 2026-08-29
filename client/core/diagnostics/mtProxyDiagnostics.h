#ifndef MTPROXYDIAGNOSTICS_H
#define MTPROXYDIAGNOSTICS_H

#include "containerDiagnostics.h"

#include <QString>

namespace ВадькаVPN {
    struct MtProxyDiagnostics : ContainerDiagnostics {
        bool upstreamReachable = false;
        int clientsConnected = -1;
        QString lastConfigRefresh;
        QString statsEndpoint;
    };

} // namespace ВадькаVPN

#endif // MTPROXYDIAGNOSTICS_H
