#ifndef CLIENT_H
#define CLIENT_H

#include "runnable.h"
#include "socket.h"

class Client : public Runnable
{
    private:
        Socket * socket;
        bool managed;
    protected:
        virtual void OnData(Socket * socket)=0;
        virtual void OnDisconnect(Socket * socket)=0;
        virtual void OnError(Socket * socket, int & error)=0;
    public:
        Client(void);
        Client(Socket * socket, bool managed = true);
        ~Client(void);

        void run(void);

        Socket * getSocket(void);
        void setSocket(Socket * socket);

        bool getManaged(void);
        void setManaged(bool managed);
};

#endif//CLIENT_H
