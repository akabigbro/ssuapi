#ifndef TCPSERVER_H
#define TCPSERVER_H

#ifndef LISTEN_PENDING
#define LISTEN_PENDING 5
#endif//LISTEN_PENDING

#include "server.h"
#include "tcpsocket.h"

class TcpServer : public Server
{
    private:
        int pending;

        void Execute(void);
    public:
        TcpServer(void);
        TcpServer(TcpSocket * socket, bool managed = true, int pending = LISTEN_PENDING);
};

#endif//TCPSERVER_H
