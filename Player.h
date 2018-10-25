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
public:
    bool initPlayer(vector<Tie*> const& ties);
    bool addTie(Tie* tie);
};


#endif //SCRABBLE_PLAYER_H
