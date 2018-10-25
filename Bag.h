//
// Created by riham on 24/10/18.
//

#ifndef SCRABBLE_BAG_H
#define SCRABBLE_BAG_H

#include <bits/stdc++.h>
#include "Tie.h"

using namespace std;

class Bag {
    map<char, int> pieces = {{'Z', 1}, {'X', 1}, {'Q', 1}, {'K', 1}, {'J', 1},
                             {'-', 2}, {'Y', 2}, {'W', 2}, {'V', 2}, {'P', 2}, {'M', 2}, {'H', 2}, {'F', 2}, {'C', 2}, {'B', 2},
                             {'G', 3},
                             {'U', 4}, {'S', 4}, {'L', 4}, {'D', 4},
                             {'T', 6}, {'R', 6}, {'N', 6},
                             {'O', 8},
                             {'I', 9}, {'A', 9},
                             {'E', 12}};
    map<char, int> scores = {{'-', 0},
                             {'A', 1}, {'E', 1}, {'I', 1}, {'L', 1}, {'N', 1}, {'O', 1}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1},
                             {'D', 2}, {'G', 2},
                             {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
                             {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
                             {'K', 5},
                             {'J', 8}, {'X', 8},
                             {'Q', 10}, {'Z', 10}};
    vector<Tie*> bag;
public:
    // initialize the bag vector
    void initBag();
    // returns the length of the bag
    int bagLen();
    // get a tie
    Tie* getTie(int index);
    // overriding the cout operator
    friend ostream& operator<<(ostream& os, Bag const& myObj);
};


#endif //SCRABBLE_TIE_H
