#include <iostream>
#include <vector>
#include <winsock2.h>
using namespace std;

class Connection{
    private:
        SOCKET conSocket;
    public:
        Connection(SOCKET conSocket);
        void sendMessage(string msg);
        string recieveMessage();
};