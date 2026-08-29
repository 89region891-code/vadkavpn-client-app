sc stop ВадькаVPNWGTunnel$ВадькаVPNVPN
sc delete ВадькаVPNWGTunnel$ВадькаVPNVPN
taskkill /IM "ВадькаVPNVPN-service.exe" /F
taskkill /IM "ВадькаVPNVPN.exe" /F
exit /b 0
