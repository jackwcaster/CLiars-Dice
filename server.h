#include <iostream>
#include <vector>
#include <winsock.h>
using namespace std;

class Server{
    private:
        SOCKET serverSocket;
        int port;
    public:
        Server();
        Server(int port);
        void start();
        SOCKET acceptClient();
};

class Connection{
    private:
        SOCKET conScoket;
    public:
        Connection(SOCKET conSocket);
        void sendMessage(string msg);
        string recieveMessage();
};

class Players{
    private:
    public:
};

class Game{
    public:
    private:
};



//connection, game, player laters