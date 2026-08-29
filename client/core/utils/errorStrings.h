#ifndef ERRORSTRINGS_H
#define ERRORSTRINGS_H

#include <QDebug>

#include "core/utils/errorCodes.h"

using namespace ВадькаVPN;

QString errorString(ErrorCode code);

QDebug operator<<(QDebug debug, const ErrorCode &e);

#endif // ERRORSTRINGS_H
