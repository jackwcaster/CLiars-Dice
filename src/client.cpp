#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2), &wsaData);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(6767);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr));

    // std::string msg = "Hello server!";
    // send(sock, msg.c_str(), msg.size(), 0);

    while(true){
    string msg;
    getline(cin, msg);
    send(sock, msg.c_str(), msg.size(), 0);
    // recv(sock, nullptr, 0, 0);
    }

    closesocket(sock);
    WSACleanup();
}