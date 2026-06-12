#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player{
        vector<int> dice;
        string name;
        void setName(string& name);
        void rollDice();
        int removeDice();
};
