//
// Created by riham on 24/10/18.
//

#include "Player.h"

Player::Player(int playerId) : playerId(playerId) {}

bool Player::initPlayer(vector<Tie*> const& ties) {
    if (ties.size() > PLAYER_TIES_SIZE) return false;
    for (Tie* t: ties) t->setPlayerId(playerId);

    myTies = ties;
    return true;
}

bool Player::addTie(Tie* tie) {
    if (myTies.size() >= PLAYER_TIES_SIZE) return false;
    tie->setPlayerId(playerId);
    myTies.push_back(tie);
    return true;
}


ostream& operator<<(ostream& os, Player const& myObj) {
    os << "\nPlayer: " << myObj.playerId << "\t ties: ";
    for (auto &i : myObj.myTies) {
        os << i << " ";
    }
    os << endl;
    return os;
}