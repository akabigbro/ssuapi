#include "tcpserver.h"

void TcpServer::Execute(void)
{
    TcpSocket * socket = (TcpSocket *) getSocket();
    socket->Listen(pending);
    while (IsRunning())
    {
        TcpSocket * connection = new TcpSocket;
        try
        {
            socket->Accept(connection);
            OnConnect(connection);
        }
        catch (int & ex)
        {
            delete connection;
            OnError(socket, ex);
            Terminate();
        }
    }
}

TcpServer::TcpServer(void)
    : pending(LISTEN_PENDING)
{
}

TcpServer::TcpServer(TcpSocket * socket, bool managed, int pending)
    : Server(socket, managed), pending(pending)
{
}
