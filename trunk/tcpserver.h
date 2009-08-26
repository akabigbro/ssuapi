#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "server.h"
#include "tcpsocket.h"

class TcpServer : public Server
{
    private:
        void Execute(void);
    public:
        TcpServer(void);
        TcpServer(TcpSocket * socket, bool managed = true);
};

#endif//TCPSERVER_H
