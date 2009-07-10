#ifndef UDPSERVER_H
#define UDPSERVER_H

#include "udpsocket.h"
#include "server.h"

class UdpServer : public Server
{
    public:
        UdpServer(UdpSocket * socket, bool managed = true) : Server(socket, managed) {};
};

#endif//UDPSERVER_H
