//
// Created by riham on 24/10/18.
//

#include "Bag.h"
void Bag::initBag() {
    for (char i='A'; i <= 'Z'; i++) {
        for (int j = 0; j < pieces[i]; j++) {
            bag.push_back(new Tie(i, scores[i]));
        }
    }
//    this represents the blank ties
    bag.push_back(new Tie('-', scores['-']));
    bag.push_back(new Tie('-', scores['-']));
}

int Bag::bagLen() {
    return (int)bag.size();
}

Tie* Bag::getTie(int index) {
    Tie* myTie = bag[index];
    bag.erase(bag.begin()+index);
    return myTie;
}

// a friend function for printing the bag
ostream& operator<<(ostream& os, Bag const& myObj) {
    for (Tie* b: myObj.bag) {
        cout << b << "\t";
    }
}