#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <initializer_list>
#include "player.h"

using namespace std;

void Player::setName(string& name){
    this->name = name;
    return;
}
void Player::rollDice(){
    srand(time({})); //seed rand, hopefully happens at diff time 
    for(auto x: dice){
        x = rand()%6+1;
    }
}
int Player::removeDice(){
    dice.pop_back();
    return dice.size();
}