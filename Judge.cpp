//
// Created by riham on 26/10/18.
//

#include "Judge.h"
#include "Bag.h"

int Judge::applyMove(const Move &move, Board &board, Player &player) {
    int score = 0, x = move.x, y = move.y;
    string word = move.word;

    if (move.direction == RIGHT) {
        // right
        int cnt = 0;
        while (cnt < word.size()) {
            // if it's successfully put then it was empty place, so remove it from the player
            int tie = int(word[cnt]-'A');
            if (board.putTieMove(x, y, tie)) {
                player.playTie(tie);
                score += board.getMultiplier(x, y) * bag.getTieScore(tie);
            }
            y++;
            cnt++;
        }
    } else if (move.direction == LEFT) {
        // left
        int cnt = word.size()-1;
        while (cnt >= 0) {
            int tie = int(word[cnt]-'A');
            if (board.putTieMove(x, y, tie)) {
                player.playTie(tie);
                score += board.getMultiplier(x, y) * bag.getTieScore(tie);
            }
            y--;
            cnt--;
        }
    } else if (move.direction == UP) {
        // up
        int cnt = 0;
        while (cnt >= 0) {
            int tie = int(word[cnt]-'A');
            if (board.putTieMove(x, y, tie)) {
                player.playTie(tie);
                score += board.getMultiplier(x, y) * bag.getTieScore(tie);
            }
            x++, cnt++;
        }

    } else {
        // down
        int cnt = word.size()-1;
        while (cnt >= 0) {
            int tie = int(word[cnt]-'A');
            if (board.putTieMove(x, y, tie)) {
                player.playTie(tie);
                score += board.getMultiplier(x, y) * bag.getTieScore(tie);
            }
            x--, cnt--;
        }
    }
    return score;
}