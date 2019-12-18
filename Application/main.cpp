#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>
#include "usermodel.h"
#include "customermodel.h"
#include "serviceaccessor.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QQuickStyle::setStyle("Material");
    QGuiApplication app(argc, argv);

    UserModel::registerMe("Users");
    CustomerModel::registerMe("Customer");

    serviceaccessor *serviceAccessor = new serviceaccessor();


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("serviceAccessor",serviceAccessor);

    engine.addImportPath(":/qml");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
