#include <QCoreApplication>
#include <QGuiApplication>
#include <QProcess>
#include <QQmlEngine>
#include <QTime>
#include <QThread>
#include <QTimer>

#include "Database.h"

static void qRegister()
{
    qmlRegisterSingletonType<Database>("UI", 1, 0, "Database",
        [](QQmlEngine *engine, QJSEngine *scriptEngine)->QObject* {
            Q_UNUSED(engine)
            Q_UNUSED(scriptEngine)
            return Database::instance();
        }
    );
}
Q_COREAPP_STARTUP_FUNCTION(qRegister)


Database* Database::instance()
{
    static Database *_instance = nullptr;
    if (_instance == nullptr) {
        _instance = new Database;
        if (_instance) {
            QQmlEngine::setObjectOwnership(_instance, QQmlEngine::CppOwnership);

            if (QThread::currentThread() != QGuiApplication::instance()->thread()) {
                _instance->moveToThread(QGuiApplication::instance()->thread());
            }
        }
    }
    return _instance;
}

int Database::getDataDB()
{
    return data;
}

void Database::setDataDB(int newData)
{
    data = newData;
    Q_EMIT dataDBChanged();
}


Database::Database(QObject *parent) : QObject(parent)
{
    data = 8;
}
