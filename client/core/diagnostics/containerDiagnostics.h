#ifndef CONTAINERDIAGNOSTICS_H
#define CONTAINERDIAGNOSTICS_H

namespace ВадькаVPN
{
    struct ContainerDiagnostics
    {
        bool available = false;
        bool portReachable = false;

        virtual ~ContainerDiagnostics() = default;
    };

} // namespace ВадькаVPN

#endif // CONTAINERDIAGNOSTICS_H
