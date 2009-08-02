#include "tcpserver.h"

void TcpServer::Execute(void)
{
    while (IsRunning())
    {
        TcpSocket * socket = (TcpSocket *) getSocket();
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
{
}

TcpServer::TcpServer(TcpSocket * socket, bool managed)
    : Server(socket, managed)
{
}
