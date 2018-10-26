#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<string>
#include <sstream>
#include "Move.h"
#include "Board.h"
#include "Bag.h"
#include "Player.h"
#include "Tie.h"
#include <time.h>

using namespace std;

# define depth 10
# define S 10

///implement for omnia
double huristicBoard(const Board &board) {
	return 0;
}
/// implement for ghada and walaa
Move huristicMoves(Board board,Player ana,Player opponent) {
	Move m;
	return m;

}
// implement for riham
int  applyMove(const Move & move, Board & board,Player & p ) {
	int score = 0;
	return score;
}


double ProbabilisticSearch(int idx,Board & board,bool game,Player ana,Player opponent,Bag & bag) {
	if (board.close() || idx >= depth) {////////
		return huristicBoard(board);
		// mfrod azod 7aga hna huristic of board
	}
	double ret = 0;
	for (int i = 0; i < S; ++i) {
		double p;
		if (game == 1) {
			p = radom_rack(bag, opponent);
			Move move = huristicMoves(board, opponent , ana);
			int score=applyMove(move, board, opponent );
			ret -= p*ProbabilisticSearch(idx + 1, board, 0,
				ana, opponent, bag
			) + score;
		}
		else {
			p = radom_rack(bag, ana);
			Move move = huristicMoves(board,ana, opponent);
			int score = applyMove(move, board, ana);
			ret += p*ProbabilisticSearch(idx + 1, board, 1,
				ana, opponent, bag
			) + score;
		}

	}
	return ret;
}

double radom_rack(Bag & bag, Player &  opponent) {
	double p = 1.0;
	srand(time(NULL));
	int tot = bag.bagLen();
	while (opponent.get() < 7&&tot) {////// for omnia
		bool x = false;
		int r = rand() % 27;
		while (!bag.get(r)) {//// for omnia
			r = rand() % 27;
		}
		p = p* bag.get(r) * 1.0 / tot;/////for omnia
		bag.removeTie(r);
		tot--;
		opponent.addTie(r);
		
	}
	return p;
}
// ana mb3otly acctions klaha tnf3 tt3ml rihaaaaaaaaaaaaaaaaaam
Move nextPlay(const vector<Move>&plays, Board board, Bag bag , Player ana ) {
	double mx = -1e9;
	int playIdx = 0;
	int size = plays.size();
	for (int i = 0; i < plays.size(); ++i) {
		int score=applyMove(plays[i], board, ana);
		Player opponent(2);/////for omnia
		double expectedValue = ProbabilisticSearch(0, board, 1, ana, opponent, bag)+score/1.0/size;
		if (mx < expectedValue) {
			mx=expectedValue;
			playIdx = i;
		}
	}
	return plays[playIdx];
}
