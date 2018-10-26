#include <iostream>
#include "Bag.h"
#include "Board.h"
#include "Player.h"


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
    cout << "----------------------------------------------\n";
    cout << bag;
    cout << "----------------------------------------------\n";

    Player player1 = Player(1);
    player1.addTie(bag.getTie(10));
    cout << player1;
    return 0;
}