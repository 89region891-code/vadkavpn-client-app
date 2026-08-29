#ifndef ВадькаVPN_APPLICATION_H
#define ВадькаVPN_APPLICATION_H

#include <QCommandLineParser>
#include <QNetworkAccessManager>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
  #include <QGuiApplication>
#else
  #include <QApplication>
#endif
#include <QClipboard>

#include "core/controllers/coreController.h"
#include "secureQSettings.h"
#include "ui/controllers/marketplaceUpdateController.h"
#include "vpnConnection.h"
#include "ui/models/containerProps.h"
#include "ui/models/protocolProps.h"

#define amnApp (static_cast<ВадькаVPNApplication *>(QCoreApplication::instance()))

#if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
  #define ВадькаVPN_BASE_CLASS QGuiApplication
#else
  #define ВадькаVPN_BASE_CLASS QApplication
#endif

class ВадькаVPNApplication : public ВадькаVPN_BASE_CLASS
{
    Q_OBJECT
public:
    ВадькаVPNApplication(int &argc, char *argv[]);
    virtual ~ВадькаVPNApplication();

    void init();
    void registerTypes();
    void loadFonts();
    bool parseCommands();

#if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS) && !defined(MACOS_NE)
    void startLocalServer();
#endif

    QQmlApplicationEngine *qmlEngine() const;
    QNetworkAccessManager *networkManager();
    QClipboard *getClipboard();

public slots:
    void forceQuit();

private:
    static bool m_forceQuit;
    QQmlApplicationEngine *m_engine {};
    SecureQSettings* m_settings;

    QScopedPointer<CoreController> m_coreController;
    QScopedPointer<MarketplaceUpdateController> m_marketplaceUpdateController;

    QSharedPointer<ContainerProps> m_containerProps;
    QSharedPointer<ProtocolProps> m_protocolProps;

    QCommandLineParser m_parser;

    QCommandLineOption m_optAutostart;
    QCommandLineOption m_optCleanup;
    QCommandLineOption m_optConnect;
    QCommandLineOption m_optImport;

    QSharedPointer<VpnConnection> m_vpnConnection;
    QThread m_vpnConnectionThread;

    QNetworkAccessManager *m_nam;
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // ВадькаVPN_APPLICATION_H
