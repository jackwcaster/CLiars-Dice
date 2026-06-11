#include <iostream>
#include <vector>
#include <server.h>
#include <winsock2.h>
#include <ws2tcpip.h>

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
}

SOCKET Server::acceptClient(){
    return accept(serverSocket, nullptr, nullptr);
}