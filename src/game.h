#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <vector>
#include "player.h"
using namespace std;

class Game{
    private:
        vector<Player> players;
        int turn;
};