package org.ВадькаVPN.vpn

import org.ВадькаVPN.vpn.protocol.Protocol
import org.ВадькаVPN.vpn.protocol.awg.Awg
import org.ВадькаVPN.vpn.protocol.openvpn.OpenVpn
import org.ВадькаVPN.vpn.protocol.wireguard.Wireguard
import org.ВадькаVPN.vpn.protocol.xray.Xray

enum class VpnProto(
    val label: String,
    val processName: String,
    val serviceClass: Class<out ВадькаVPNVpnService>
) {
    WIREGUARD(
        "WireGuard",
        "org.ВадькаVPN.vpn:ВадькаVPNAwgService",
        AwgService::class.java
    ) {
        override fun createProtocol(): Protocol = Wireguard()
    },

    AWG(
        "ВадькаVPNWG",
        "org.ВадькаVPN.vpn:ВадькаVPNAwgService",
        AwgService::class.java
    ) {
        override fun createProtocol(): Protocol = Awg()
    },

    OPENVPN(
        "OpenVPN",
        "org.ВадькаVPN.vpn:ВадькаVPNOpenVpnService",
        OpenVpnService::class.java
    ) {
        override fun createProtocol(): Protocol = OpenVpn()
    },

    XRAY(
        "XRay",
        "org.ВадькаVPN.vpn:ВадькаVPNXrayService",
        XrayService::class.java
    ) {
        override fun createProtocol(): Protocol = Xray.instance
    },

    SSXRAY(
        "SSXRay",
        "org.ВадькаVPN.vpn:ВадькаVPNXrayService",
        XrayService::class.java
    ) {
        override fun createProtocol(): Protocol = Xray.instance
    };

    private var _protocol: Protocol? = null
    val protocol: Protocol
        get() {
            if (_protocol == null) _protocol = createProtocol()
            return _protocol ?: throw AssertionError("Set to null by another thread")
        }

    protected abstract fun createProtocol(): Protocol

    companion object {
        fun get(protocolName: String): VpnProto = VpnProto.valueOf(protocolName.uppercase())
    }
}
