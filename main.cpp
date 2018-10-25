#include <iostream>
#include "Bag.h"
#include "Board.h"


int main() {
    Bag bag = Bag();
    bag.initBag();
    cout << bag;

    Board board = Board();
    board.initBoard();
    cout << board;
    cout << "----------------------------------------------\n";
    board.putTie({2, 2}, bag.getTie(5));
    cout << board;
    cout << bag;
    return 0;
}