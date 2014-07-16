#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QUdpSocket>
#define WIN32_LEAN_AND_MEAN
#define WINVER 0x0500
// We need the Windows Header and the XInput Header
#include <windows.h>
#include <Xinput.h>
#include <QHostAddress>

#pragma comment(lib, "XInput.lib")
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
private:
    QUdpSocket _socket;

signals:

public slots:
    void receive();

};

#endif // CLIENT_H
