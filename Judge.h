//
// Created by riham on 26/10/18.
//

#ifndef SCRABBLE_JUDGE_H
#define SCRABBLE_JUDGE_H


#include "Bag.h"
#include "Board.h"
#include "Player.h"
#include "Move.h"

#define RIGHT   0
#define LEFT    1
#define UP      2
#define DOWN    3

class Judge {
public:
    Judge(Bag b): bag(b) {}
    int applyMove(const Move &move, Board &board, Player &player, Bag &bag);
    bool isClosed(Board &board);
};


#endif //SCRABBLE_JUDGE_H
