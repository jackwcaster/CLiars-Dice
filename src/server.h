#include <iostream>
#include <vector>
#include <winsock2.h>
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


class Players{
    private:
    public:
};

class Game{
    public:
    private:
};



//connection, game, player laters