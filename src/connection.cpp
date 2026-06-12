#include <iostream>
#include <vector>
#include <winsock2.h>
#include "connection.h"
using namespace std;


Connection::Connection(SOCKET conSocket){
    this -> conSocket = conSocket;
}
void Connection::sendMessage(string msg){
    // send(conSocket, msg.c_str(), msg.size(), 0); //must convert to C string
            int result =
            send(conSocket,
                msg.c_str(),
                msg.size(),
                0);

        cout << "send result = "
            << result
            << endl;

        if(result == SOCKET_ERROR)
        {
            cout << "send failed: "
                << WSAGetLastError()
                << endl;
        }
}
string Connection::recieveMessage(){
    char buff [1024];
    int bytes = recv(conSocket, buff, sizeof(buff), 0);

if (bytes == SOCKET_ERROR)
{
    cout << "recv failed: " << WSAGetLastError() << endl;
    return "";
}

if (bytes == 0)
{
    cout << "client disconnected\n";
    return "";
}

return string(buff, bytes);
}