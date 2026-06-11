#include <iostream>
#include <vector>
#include <winsock2.h>
#include "connection.h"
using namespace std;


Connection::Connection(SOCKET conSocket){
    this -> conSocket = conSocket;
}
void Connection::sendMessage(string msg){
    send(conSocket, msg.c_str(), msg.size(), 0); //must convert to C string
}
string Connection::recieveMessage(){
    char buff [1024];
    int bytes = recv(conSocket, buff, sizeof(buff), 0);
    return string(buff, bytes);
}