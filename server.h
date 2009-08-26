#ifndef SERVER_H
#define SERVER_H

#include "thread.h"
#include "socket.h"

class Server : public Thread
{
    private:
        Socket * socket;
        bool managed;

        virtual void Execute(void);
    protected:
        virtual void OnConnect(Socket * socket)=0;
        virtual void OnClose(Socket * socket)=0;
        virtual void OnError(Socket * socket, int & error)=0;

        Socket * getSocket(void);
    public:
        Server(void);
        Server(Socket * socket, bool managed = true);
        ~Server(void);

        void setSocket(Socket * socket);
        void setManaged(bool managed);
};

#endif//SERVER_H
