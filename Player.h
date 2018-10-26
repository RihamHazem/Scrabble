//
// Created by riham on 24/10/18.
//

#ifndef SCRABBLE_PLAYER_H
#define SCRABBLE_PLAYER_H

#include <bits/stdc++.h>
#include "Tie.h"

using namespace std;

static const int PLAYER_TIES_SIZE = 7;

class Player {
    vector<Tie*> myTies;
    int playerId;
public:
    Player(int playerId);
    bool initPlayer(vector<Tie*> const& ties);
    bool addTie(Tie* tie);
    friend ostream& operator<<(ostream& os, Player const& myObj);
};


#endif //SCRABBLE_PLAYER_H
