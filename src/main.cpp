#include <iostream>
#include <winsock2.h>
// #include <ws2tcpip.h>
#include "server.h"
// #include "connection.h"

#pragma comment(lib, "Ws2_32.lib")

int main() {
    WSADATA wsaData;

    WSAStartup(MAKEWORD(2,2), &wsaData);

    Server server(6767); // set port
    cout<<"Starting server"<<endl;
    server.start(); //Need a start function
    cout<<"Server started, waiting for client"<<endl;
    SOCKET client = server.acceptClient(); //make a socket for one client
    cout<<"Client connected"<<endl;
    Connection connect(client); // create a connection with the client socket?
    connect.sendMessage("test"); //test msg
    // string msg = connect.recieveMessage();
    while(true)
{
    string msg =
        connect.recieveMessage();
        connect.sendMessage("test");
    cout << msg << endl;
}
    // cout<<msg<<endl;

    WSACleanup();
}
// g++ interface.cpp server.cpp connection.cpp -o main -lws2_32