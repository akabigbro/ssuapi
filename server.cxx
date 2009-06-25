#include "server.h"

void Server::Execute(void)
{
    while (IsRunning())
    {
        char buffer[32] = {0};
        try
        {
            if (0 < socket->Read(buffer, sizeof(buffer), MSG_PEEK))
            {
                OnConnect(socket);
            }
            else
            {
                OnClose(socket);
                Terminate();
            }
        }
        catch (int & ex)
        {
            OnError(socket, ex);
            Terminate();
        }
    }
}

Server::Server(Socket * socket, bool managed)
    : socket(socket), managed(managed)
{
}

Server::~Server(void)
{
    if (managed)
    {
        delete socket;
    }
}
