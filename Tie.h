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

    Tie(char tc, int s) {
        tie_char = tc;
        score = s;
    }

    friend ostream& operator<<(ostream& os, Tie* myObj) {
        if (myObj == nullptr) return os << "NULL";
        return os << "(" << myObj->tie_char << ", " << myObj->score << ")";
    }
};

#endif //SCRABBLE_TIE_H
