#include "client.h"

void Client::Execute(void)
{
    while (!Terminated)
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

Client::Client(Socket * socket, bool managed)
    : socket(socket), managed(managed)
{
}

Client::~Client(void)
{
    delete socket;
}
