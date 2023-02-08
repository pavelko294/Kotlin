#ifndef COM_PORT_H
#define COM_PORT_H

#include <QDeclarativeItem>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>

class com_portData;

class com_port
{
public:
    com_port();
    com_port(const com_port &);
    com_port &operator=(const com_port &);
    ~com_port();

private:
    QSharedDataPointer<com_portData> data;
};

#endif // COM_PORT_H