//
// Created by riham on 24/10/18.
//

#include "Bag.h"

void Bag::initBag() {
    for (char i=0; i <= 26; i++) {
        bag[i] += pieces[i];
    }
}

int Bag::bagLen() {
    return bagSize;
}

int Bag::removeTie(int index) {
    if (bag[index] == 0) return -1; // check that this char exists
    bag[index]--, bagSize--;
    return scores[index];
}

int Bag::getTieScore(int index) {
    return scores[index];
}

// a friend function for printing the bag
ostream& operator<<(ostream& os, Bag const& myObj) {
    int cnt = 0;
    for (int b: myObj.bag) {
        os << "( char=" << char(cnt+'A') << ", count=" << b << ", score=" << myObj.scores[cnt++] << " )\t";
    }
    return os << endl;
}