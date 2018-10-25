//
// Created by riham on 24/10/18.
//

#ifndef SCRABBLE_BOARD_H
#define SCRABBLE_BOARD_H

#include <bits/stdc++.h>
#include "Tie.h"

using namespace std;

static const int BOARD_SIZE = 15;
static const _3xW_SIZE = 7;
static const _2xW_SIZE = 12;
static const _3xL_SIZE = 12;
static const _2xL_SIZE = 24;

class Board {

    int multiplier[BOARD_SIZE][BOARD_SIZE];
    Tie* board[BOARD_SIZE][BOARD_SIZE];
    pair<int, int>_3xW[_3xW_SIZE] = {{1, 1}, {8, 1}, {15, 1}, {1, 8},
                            {1, 15}, {8, 15}, {15, 15}};
    pair<int, int> _2xW[_2xW_SIZE] = {{2, 2}, {3, 3}, {4, 4}, {5, 5},
                             {14, 2}, {13, 3}, {12, 4}, {11, 5},
                             {11, 11}, {12, 12}, {13, 13}, {14, 14}};
    pair<int, int> _3xL[_3xL_SIZE] = {{6, 2}, {10, 2},
                             {2, 6}, {6, 6}, {10, 6}, {14, 6},
                             {2, 10}, {6, 10}, {10, 10}, {14, 10},
                             {6, 14}, {10, 14}};
    pair<int, int> _2xL[_2xL_SIZE] = {{4, 1}, {12, 1},
                             {7, 3}, {9, 3},
                             {1, 4}, {8, 4}, {15, 4},
                             {3, 7}, {7, 7}, {9, 7}, {13, 7},
                             {4, 8}, {12, 8},
                             {3, 9}, {7, 9}, {9, 9}, {13, 9},
                             {1, 12}, {8, 12}, {15, 12},
                             {7, 13}, {9, 13},
                             {4, 15}, {12, 15}};
public:
    Board();
    void initBoard();
    friend ostream& operator<<(ostream& os, Board const& myObj);
    bool putTie(pair<int, int> pos, Tie *tie);
    bool isValidMove(pair<int, int> pos, Tie* tie);
    string getHorizontalWord(pair<int, int> pos);
    string getVerticalWord(pair<int, int> pos);
    bool isValidWords(string& horWord, string& verWord);
};


#endif //SCRABBLE_BOARD_H
