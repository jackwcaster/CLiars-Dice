#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <vector>
#include "player.h"
using namespace std;

class Game{
        vector<Player> players;
        int turn;

        Game();
        Game(vector<Player>& players);
        void addPlayer(Player& added);
        void broadcast(string& message);
        bool startGame();
};