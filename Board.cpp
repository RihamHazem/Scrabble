//
// Created by riham on 24/10/18.
//

#include "Board.h"

Board::Board() {
    memset(multiplier, 0, sizeof multiplier);
    for (auto &i: board) {
        for (auto &j: i) {
            j = nullptr;
        }
    }
}

void Board::initBoard() {
//    update board with 3xL
    for (auto &it: _3xL) {
        multiplier[it.first-1][it.second-1] = 3;
    }
//    update board with 2xL
    for (auto &it: _2xL) {
        multiplier[it.first-1][it.second-1] = 2;
    }
////////////////////////////////////////////
//    update board with 3xW
//    it triples the score of the current word
    for (auto &it: _3xW) {
        multiplier[it.first-1][it.second-1] = 30;
    }
//    update board with 2xW
//    it doubles the score of the current word
    for (auto it: _2xW) {
        multiplier[it.first-1][it.second-1] = 20;
    }
}

ostream& operator<<(ostream& os, Board const& myObj) {
    for (auto &i : myObj.board) {
        for (Tie* j : i) {
            os << j << " ";
        }
        os << endl;
    }
    return os;
}

bool Board::putTie(pair<int, int> pos, Tie *tie) {
    if (board[pos.first][pos.second] != nullptr) return false;
    board[pos.first][pos.second] = tie;
    return true;
}

string Board::getHorizontalWord(pair<int, int> pos) {
    string horizontalWord;
    int r = pos.first, c = pos.second;
    while (c >= 0 && board[r][c] != nullptr) {
        horizontalWord = board[r][c]->tie_char + horizontalWord;
        c--;
    }
    c = pos.second + 1;
    while (c < BOARD_SIZE && board[r][c] != nullptr) {
        horizontalWord += board[r][c]->tie_char;
        c++;
    }
    return horizontalWord;
}

string Board::getVerticalWord(pair<int, int> pos) {
    string verticalWord;
    int r = pos.first, c = pos.second;
    while (r >= 0 && board[r][c] != nullptr) {
        verticalWord = board[r][c]->tie_char + verticalWord;
        r--;
    }
    r = pos.first+1;
    while (r < BOARD_SIZE && board[r][c] != nullptr) {
        verticalWord += board[r][c]->tie_char;
        r++;
    }
    return verticalWord;
}

bool Board::isValidMove(pair<int, int> pos, Tie *tie) {
    string horizontalWord = getHorizontalWord(pos), verticalWord = getVerticalWord(pos);
    // call the dictionary module to make sure that horizontal and vertical words are correct
    return isValidWords(horizontalWord, verticalWord);
}

bool Board::isValidWords(string& horWord, string& verWord) {
    // it calls the dictionary to make sure that these words exist in it
    return true;
}

