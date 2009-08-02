#include "client.h"

void Client::Execute(void)
{
    while (NULL != socket && !Terminated)
    {
        char buffer[32] = {0};
        try
        {
            if (0 < socket->Read(buffer, sizeof(buffer), MSG_PEEK))
            {
                OnData(socket);
            }
            else
            {
                OnDisconnect(socket);
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
