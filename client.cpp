#include "client.h"
#include <QDebug>

Client::Client(QObject *parent) :
    QObject(parent)
{
    _socket.bind(545454);
    connect(&_socket,SIGNAL(readyRead()),this,SLOT(receive()));
}

void Client::receive()
{
    while(_socket.hasPendingDatagrams()){
        QByteArray data;
        _socket.readDatagram(data.data(),512);
        _socket.flush();
        XINPUT_VIBRATION Vibration;

        // Zeroise the Vibration
        ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

        if(data.toInt()&XINPUT_GAMEPAD_A){
            // Set the Vibration Values
            Vibration.wLeftMotorSpeed = 0;
            Vibration.wRightMotorSpeed = 0;

        }
        if(data.toInt()&XINPUT_GAMEPAD_X){
            // Set the Vibration Values
            Vibration.wLeftMotorSpeed = 65535;
            Vibration.wRightMotorSpeed = 65535;
        }
        if(data.toInt()&XINPUT_GAMEPAD_Y){
            // Set the Vibration Values
            Vibration.wLeftMotorSpeed = 65535;
            Vibration.wRightMotorSpeed = 65535;
        }
        if(data.toInt()&XINPUT_GAMEPAD_B){
            // Set the Vibration Values
            Vibration.wLeftMotorSpeed = 65535;
            Vibration.wRightMotorSpeed = 65535;
        }

        // Vibrate the controller
        XInputSetState(0, &Vibration);
    }
}
