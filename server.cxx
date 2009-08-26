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

Socket * Server::getSocket(void)
{
    return socket;
}

Server::Server(void)
    : socket(NULL), managed(false)
{
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

void Server::setSocket(Socket * socket)
{
    this->socket = socket;
}

void Server::setManaged(bool managed)
{
    this->managed = managed;
}
