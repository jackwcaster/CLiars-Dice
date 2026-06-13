#pragma once
#include <iostream>
#include <vector>
#include <winsock2.h>
#include "connection.h"
using namespace std;

class Server{
    private:
        SOCKET serverSocket;
        int port;
        vector<Connection*> clients;
    public:
        Server();
        Server(int port);
        void start();
        SOCKET acceptClient();
        void acceptClinets();
        void handleClient(Connection* client);
        void broadcast(string msg);
};




//connection, game, player laters