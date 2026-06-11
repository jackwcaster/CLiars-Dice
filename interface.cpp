#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "server.h"

#pragma comment(lib, "Ws2_32.lib")

int main() {
    WSADATA wsaData;

    WSAStartup(MAKEWORD(2,2), &wsaData);

    Server server(6767); // set port
    server.start(); //Need a start function
    SOCKET client = server.acceptClient(); //make a socket for one client
    Connection connect(client); // create a connection with the client socket?
    connect.sendMessage("test"); //test msg

    WSACleanup();
}