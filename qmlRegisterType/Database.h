#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

class Database : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int dataDB READ getDataDB WRITE setDataDB NOTIFY dataDBChanged)
public:
    static Database* instance();

    int getDataDB();
    void setDataDB(int newData);

Q_SIGNALS:
    void dataDBChanged();


private:
    explicit Database(QObject *parent = nullptr);

signals:

private:
    int data;

};

#endif // DATABASE_H
