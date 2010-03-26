#include "client.h"

Client::Client(void)
    : socket(NULL), managed(false)
{
}

Client::Client(Socket * socket, bool managed)
    : socket(socket), managed(managed)
{
}

Client::~Client(void)
{
    if (managed)
    {
        delete socket;
    }
}

void Client::run(void)
{
    char buffer[32] = {0};
    try
    {
        while (0 < socket->Read(buffer, sizeof(buffer), MSG_PEEK))
        {
            OnData(socket);
        }
        OnDisconnect(socket);
        }
    catch (int & ex)
    {
        OnError(socket, ex);
    }
}

Socket * Client::getSocket(void)
{
    return socket;
}

void Client::setSocket(Socket * socket)
{
    this->socket = socket;
}

bool Client::getManaged(void)
{
    return managed;
}

void Client::setManaged(bool managed)
{
    this->managed = managed;
}
