//
// Created by riham on 24/10/18.
//

#include "Player.h"

bool Player::initPlayer(vector<Tie*> const& ties) {
    if (ties.size() > PLAYER_TIES_SIZE) return false;
    myTies = ties;
    return true;
}

bool Player::addTie(Tie* tie) {
    if (myTies.size() >= PLAYER_TIES_SIZE) return false;
    myTies.push_back(tie);
    return true;
}