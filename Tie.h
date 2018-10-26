//
// Created by riham on 24/10/18.
//

#ifndef SCRABBLE_TIE_H
#define SCRABBLE_TIE_H

#include <bits/stdc++.h>
using namespace std;

struct Tie {
    char tie_char;
    int score;
    int playerId = -1;

    Tie(char tc, int s) {
        tie_char = tc;
        score = s;
    }

    void setPlayerId(int pid) {
        playerId = pid;
    }

    friend ostream& operator<<(ostream& os, Tie* myObj) {
        if (myObj == nullptr) return os << "NULL";
        return os << "( tie_char=" << myObj->tie_char << ", score=" << myObj->score << ", playerId=" << myObj->playerId << ")";
    }
};

#endif //SCRABBLE_TIE_H
