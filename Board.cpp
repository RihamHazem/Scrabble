//
// Created by riham on 24/10/18.
//

#include "Board.h"

Board::Board() {
    memset(multiplier, 0, sizeof multiplier);
    for (auto &i: board) {
        for (auto &j: i) {
            j = -1;
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
        for (int j : i) {
            os << char(j+'A') << " ";
        }
        os << endl;
    }
    return os;
}

bool Board::putFirstTie(int tie) {
    if (board[starPos][starPos] != -1) return false;
    board[starPos][starPos] = tie;
    return true;
}

bool Board::putTie(int posX, int posY, int tie) {
    if (board[posX][posY] != -1 || !isValidMove(posX, posY, tie)) return false;
    board[posX][posY] = tie;
    return true;
}

bool Board::isValidMove(int posX, int posY, int tie) {
    board[posX][posY] = tie;
    string horizontalWord = getHorizontalWord(posX, posY), verticalWord = getVerticalWord(posX, posY);
    cout << endl << horizontalWord << " " << verticalWord << endl;
    // call the dictionary module to make sure that horizontal and vertical words are correct
    // and make sure that the current tie is appended to at least one another tie
    if ((horizontalWord.size() > 1 || verticalWord.size() > 1) && isValidWords(horizontalWord, verticalWord))
        return true;
    board[posX][posY] = -1;
    return false;
}

string Board::getHorizontalWord(int posX, int posY) {
    string horizontalWord;
    int r = posX, c = posY;
    // if it's a blank tie it should be handled to be replaced by a suitable char
    while (c >= 0 && board[r][c] != -1) {
        horizontalWord = char(board[r][c]+'A') + horizontalWord;
        c--;
    }
    c = posY + 1;
    while (c < BOARD_SIZE && board[r][c] != -1) {
        horizontalWord += char(board[r][c]+'A');
        c++;
    }
    return horizontalWord;
}

string Board::getVerticalWord(int posX, int posY) {
    string verticalWord;
    int r = posX, c = posY;
    while (r >= 0 && board[r][c] != -1) {
        verticalWord = char(board[r][c]+'A') + verticalWord;
        r--;
    }
    r = posX+1;
    while (r < BOARD_SIZE && board[r][c] != -1) {
        verticalWord += char(board[r][c]+'A');
        r++;
    }
    return verticalWord;
}

bool Board::isValidWords(string& horWord, string& verWord) {
    // it calls the dictionary to make sure that these words exist in it
    return true;
}

