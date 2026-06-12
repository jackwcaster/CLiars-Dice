#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <vector>
// #include "player.h"
#include "game.h"

using namespace std;

Game::Game(){
    players = vector<Player>();
    turn = 0;
}
Game::Game(vector<Player>& players){
    this -> players = players;
    turn = 0;
}
void Game::addPlayer(Player& added){
    players.push_back(added);
    return;
}
void Game::broadcast(string& message){

}
bool Game::startGame(){
    if(players.size()>=2) {
        return true; //triggers initial dice roll or something
    }
    else{
        cout<<"Not enough players"<<endl;
    }
    return false;
}