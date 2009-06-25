#ifndef CLIENT_H
#define CLIENT_H

#include "thread.h"
#include "socket.h"

class Client : public Thread
{
    private:
        Socket * socket;
        bool managed;

        void Execute(void);
    protected:
        virtual void OnData(Socket * socket)=0;
        virtual void OnDisconnect(Socket * socket)=0;
        virtual void OnError(Socket * socket, int & error)=0;
    public:
        Client(Socket * socket, bool managed = true);
        ~Client(void);
};

#endif//CLIENT_H