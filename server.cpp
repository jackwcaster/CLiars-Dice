#include <iostream>
#include <vector>
using namespace std;

class Server{
    private:
        int serverSocket;
    public:
        Server();
        Server(int port);
        void start();
        int addClient();
};

class Connection{
    private:
    public:
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