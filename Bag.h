//
// Created by riham on 24/10/18.
//

#ifndef SCRABBLE_BAG_H
#define SCRABBLE_BAG_H

#include <bits/stdc++.h>
#include "Tie.h"

using namespace std;

class Bag {
    int pieces[27] = {9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2, 6, 8, 2, 1, 6, 4, 6, 4, 2, 2, 1, 2, 1, 2};
    int scores[27] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};
    int bag[27];
    int bagSize = 100;
public:
    // initialize the bag vector
    void initBag();
    // returns the length of the bag
    int bagLen();
    // it removes a tie from the bag and returns its score
    int removeTie(int index);
    // it gets the score of a tie
    int getTieScore(int index);
    // overriding the cout operator
    friend ostream& operator<<(ostream& os, Bag const& myObj);
};


#endif //SCRABBLE_TIE_H
