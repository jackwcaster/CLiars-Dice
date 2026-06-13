#include <iostream>
#include <vector>
#include "server.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>

using namespace std;

Server::Server(){
    port = 8080;
}

Server::Server(int port){
    this->port = port;
}

void Server::start(){
    serverSocket = socket(AF_INET, SOCK_STREAM, 0); //IPv4, TCP
    sockaddr_in serverAddress; //data type for sockets
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    listen(serverSocket, SOMAXCONN);

    acceptClinets();
}

SOCKET Server::acceptClient(){
    return accept(serverSocket, nullptr, nullptr);
}

void Server::acceptClinets(){
    while(true){
        SOCKET clientSocket =accept(serverSocket,nullptr, nullptr );

        Connection* client = new Connection(clientSocket);

        clients.push_back(client);

        cout<< "Client joined\n";

        std::thread t(&Server::handleClient, this, client );

        t.detach();
    }
}

void Server::handleClient(Connection* client){
    while(true)
    {
        string msg = client->recieveMessage();

        if(msg.empty())
        {
            break;
        }

        cout <<"Client: "<< msg << endl;

        broadcast("Server Recieved: " + msg);
    }
}

void Server::broadcast(string msg){
    for(Connection* client : clients)
    {
        client->sendMessage(msg);
    }
}