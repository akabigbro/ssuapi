#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "server.h"
#include "tcpsocket.h"

class TcpServer : public Server
{
    private:
        TcpSocket * socket;

        void Execute(void);
    public:
        TcpServer(TcpSocket * socket, bool managed = true);
};

#endif//TCPSERVER_H
