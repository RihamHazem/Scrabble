#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include <sstream>
#include <time.h>
#include "Judge.h"


using namespace std;

# define depth 10
# define S 10

Judge J;
const char st = 'A';
int cur[26]; // el letters elii ba2ya m3aya b3d ma l3bt
int deck[26]; // el letters eli fl bag wli m3a el oponent
int opponentDeck[26];

const int deckSz = 19;
///implement for omnia
long double huristicBoard(const Board &board) {
	return 0;
}
// btgeeb kol el strings eli mn 7 chars eli law et7tet fl board t3ml bingo
vector<pair<string, int>> getPossibleBingo() {
	vector<pair<string, int>>v;
	return v;

}
/// implement for ghada and walaa
//httshal
// btfilter el strings elii gayalii w btshof asln hal dy mmkn tt3ml wla l2
vector<pair<string, int> > filterPossibles(vector<pair<string, int> >& vec,
	bool play) {
	int freq[26];
	memset(freq, 0, sizeof(freq));
	vector<pair<string, int> > res;
	for (int i = 0; i < vec.size(); ++i) {
		memset(freq, 0, sizeof(freq));
		for (int j = 0; j < vec[i].first.size(); ++j)
			freq[vec[i].first[j] - st]++;
		bool fnd = true;
		for (int j = 0; j < 26; ++j)
			if ((play && (freq[j] < cur[j] || freq[j] > cur[j] + deck[j]))
				|| (!play && freq[j] != opponentDeck[j])) {
				fnd = false;
				break;
			}

		if (fnd)
			res.push_back(vec[i]);
	}
	return res;
}
double calcProbability(int freq[], int score) {
	double letterP = 1;
	int cnt = 0;
	for (int i = 0; i < 26; ++i) {
		if (cur[i] >= freq[i])
			continue;
		// cur[i] hya el 7rof eli m3aya
		freq[i] -= cur[i];
		cnt += freq[i];
		letterP *= J.pascal[deck[i]][freq[i]];
	}
	letterP /= (J.pascal[deckSz][cnt] * 1.0);
	// multiply by 2.5 if the score isn't calculated for the board
	return letterP * (50 + score);
}

double expectedBingoMe() {
	int freq[26];
	memset(freq, 0, sizeof(freq));
	vector<pair<string, int>> possible = getPossibleBingo();

	double p = 0;
	for (int i = 0; i < possible.size(); ++i) {
		memset(freq, 0, sizeof(freq));
		for (int j = 0; j < possible[i].first.size(); ++j)
			freq[possible[i].first[j] - st]++;

		// calculate the expected number of the score to make this word
		p += calcProbability(freq, possible[i].second);
	}
	return p;	// multiply  p * 0.8 assuming prob of bingo in the next play will decrease by 0.2
	///////////// don't forget ya ghada !!!!!!!!!!!!!!!
}
int expectedBingoOpponent() {
	vector<pair<string, int>> possible = getPossibleBingo();
	//////--------------- not so sure
	int mx = -1;
	for (int i = 0; i < possible.size(); ++i) {
		mx = max(mx, possible[i].second);
	}
	return mx;
	// eb3ty el mx
	//////////////// mfrod ab3t el exScore
}

double RackLeaveScore(string C) {

	double score = 0.0;

	//The weights for the first occurence of a letter
	// * means blank
	map<char, double> L1{ { 'a', 1.0 },{ 'b', -3.5 },{ 'c', -0.5 },{ 'd',
		0.0 },{ 'e', 4.0 },{ 'f', -2.0 },{ 'g', -2.0 },{ 'h', 0.5 },{
			'i', -0.5 },{ 'j', -3.0 },{ 'k', -2.5 },{ 'l', -1.0 },{ 'm',
			-1.0 },{ 'n', 0.5 },{ 'o', -1.5 },{ 'p', -1.5 },{ 'q', -11.5 },
			{ 'r', 1.5 },{ 's', 7.5 },{ 't', 0.0 },{ 'u', -3.0 },
			{ 'v', -5.5 },{ 'w', -4.0 },{ 'x', 3.5 },{ 'y', -2.0 },{ 'z',
			2.0 },{ '*', 24.5 }  // '*' means blank
	};

	//Duplicate weights
	map<char, double> L2{ { 'a', -3.0 },{ 'b', -3.0 },{ 'c', -3.5 },{ 'd',
		-2.5 },{ 'e', -2.5 },{ 'f', -2.0 },{ 'g', -2.5 },{ 'h', -3.5 },
		{ 'i', -4.0 },{ 'j', 0.0 },{ 'k', 0 },{ 'l', -2.0 },
		{ 'm', -2.0 },{ 'n', -2.5 },{ 'o', -3.5 },{ 'p', -2.5 },
		{ 'q', 0 },{ 'r', -3.5 },{ 's', -4.0 },{ 't', -2.5 },
		{ 'u', -3.0 },{ 'v', -3.5 },{ 'w', -4.5 },{ 'x', 0 },
		{ 'y', -4.5 },{ 'z', 0 },{ '*', 15.0 } };
	/*j,k,q,x,z mknsh lehm rkm w 5lthm bzero,mmkn ab2a ashelhm mn lmap dh
	w a5od rkmhm mn fo2 k2nhm msh duplicate!
	*/

	char x;
	map<char, double> m;  // The accumulative weight for each letter in the rack
	int v = 0, c = 0; //the number of vowels and constants

	for (int i = 0; i < C.length(); i++) {
		x = C[i];
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
			v++;
		else
			c++;

		if (m.count(x) == 0)
			m[x] = L1[x];
		else
			m[x] += L2[x];

		score += m[x];
	}
	//------------------------------------------------------------------
	//Vowel--Consonant Mix weights
	map<string, double> VC{ { "00", 0 },{ "01", 0 },{ "02", -1 },
	{ "03", -2 },{ "04", -3 },{ "05", -4 },{ "06", -5 },
	{ "10", -1 },{ "11", 1 },{ "12", 1 },{ "13", 0 },{ "14", -1 },{
		"15", -2 },{ "20", -2 },{ "21", 0 },{ "22", 2 },{ "23",
		2 },{ "24", 1 },{ "30", -3 },{ "31", -1 },{ "32", 1 },{
			"33", 3 },{ "40", -4 },{ "41", -2 },{ "42", 0 },{ "50",
			-5 },{ "51", -3 },{ "60", -6 } };

	string r_vc;
	r_vc = v + '0';
	r_vc += (c + '0');

	score += VC[r_vc];

	return score;
}

//----------------------->will be modified later depending on what will bs sent
double DefensiveStrategy(int A[15][15], int B[15][15], int Board[15][15],
	vector<int> newWord) {
	double perm = 0.0;
	int Wlen = newWord.size();
	/*
	newWord{0 if horizontal 1 if vertical,index 1 is the row # in case of horizantal
	and column # in case of vertical word,
	rest of number are column indexes in case of horizontal
	and row indexes in case of vertical
	*/
	//horizontal word
	if (newWord[0] == 0) {
		//search horizontally--left of the word
		for (int i = newWord[2] - 1; i >= (newWord[2] - 3) && i >= 0; i--) {
			if (Board[newWord[1]][i] == 0)	//no letter in this box
			{
				if (A[newWord[1]][i] == 1)
					perm += 0.5;
				else if (B[newWord[1]][i])
					perm += 1.5;
			}
		}
		//right of the word
		for (int i = newWord[Wlen - 1] + 1;
			i <= (newWord[Wlen - 1] + 3) && i < 15; i++) {
			if (Board[newWord[1]][i] == 0)	//no letter in this box
			{
				if (A[newWord[1]][i] == 1)
					perm += 0.5;
				else if (B[newWord[1]][i])
					perm += 1.5;
			}
		}
		//under the word
		for (int i = newWord[1] + 1; i <= (newWord[1] + 3) && i < 15; i++) {
			for (int j = newWord[2]; j <= newWord[Wlen - 1]; j++) {
				if (Board[i][j] == 0)	//no letter in this box
				{
					if (A[i][j] == 1)
						perm += 0.5;
					else if (B[i][j])
						perm += 1.5;
				}
			}
		}
		//above the word
		for (int i = newWord[1] - 1; i >= (newWord[1] - 3) && i >= 0; i--) {
			for (int j = newWord[2]; j <= newWord[Wlen - 1]; j++) {
				if (Board[i][j] == 0)	//no letter in this box
				{
					if (A[i][j] == 1)
						perm += 0.5;
					else if (B[i][j])
						perm += 1.5;
				}
			}
		}
	}
	//vertial word
	else {
		//above the word
		for (int i = newWord[2] - 1; i >= (newWord[2] - 3) && i >= 0; i--) {
			if (Board[i][newWord[1]] == 0)	//no letter in this box
			{
				if (A[i][newWord[1]] == 1)
					perm += 0.5;
				else if (B[i][newWord[1]])
					perm += 1.5;
			}
		}
		//under of the word
		for (int i = newWord[Wlen - 1] + 1;
			i <= (newWord[Wlen - 1] + 3) && i < 15; i++) {
			if (Board[i][newWord[1]] == 0)	//no letter in this box
			{
				if (A[i][newWord[1]] == 1)
					perm += 0.5;
				else if (B[i][newWord[1]])
					perm += 1.5;
			}
		}

		//right to  the word
		for (int i = newWord[1] + 1; i <= (newWord[1] + 3) && i < 15; i++) {
			for (int j = newWord[2]; j <= newWord[Wlen - 1]; j++) {
				if (Board[j][i] == 0)	//no letter in this box
				{
					if (A[j][i] == 1)
						perm += 0.5;
					else if (B[j][i])
						perm += 1.5;
				}
			}
		}
		//left to the word
		for (int i = newWord[1] - 1; i >= (newWord[1] - 3) && i >= 0; i--) {
			for (int j = newWord[2]; j <= newWord[Wlen - 1]; j++) {
				if (Board[j][i] == 0)	//no letter in this box
				{
					if (A[j][i] == 1)
						perm += 0.5;
					else if (B[j][i])
						perm += 1.5;
				}
			}
		}

	}
	return perm;
}
////// hery
/*hary(Board board, Player ana, Player opponent) {

	float num = expectedBingoMe() + expectedBingoOpponent();
}*/
Move huristicMoves(Board board,Player ana,Player opponent) {
    //hary(Board board, Player ana, Player opponent);
    Move m;
    return m;
}

long double change(Bag & bag, Player & ply, vector<char>tiles) {
    long double p = 1.0;
    srand(time(NULL));
    int tot = bag.bagLen();
    for (int i = 0; i < tiles.size(); ++i) {
        int r = rand() % 27;
        while (!bag.getTieCount(r)) {//// for omnia
            r = rand() % 27;
        }
        bag.exchangeTie(r, (int) (tiles[i] - 'A'));
        ply.addTie(r);
    }
    return p;
}

long double radom_rack(Bag & bag, Player &  opponent) {
    long double p = 1.0;
    srand(time(NULL));
    int tot = bag.bagLen();
    while (opponent.getTotalTies() < 7 && tot) {////// for omnia
        int r = rand() % 27;
        while (!bag.getTieCount(r)) {//// for omnia
            r = rand() % 27;
        }
        p = p * (bag.getTieCount(r) * 1.0 / tot);/////for omnia
        bag.removeTie(r);
        tot--;
        opponent.addTie(r);
    }
    return p;
}

long double ProbabilisticSearch(int idx,Board & board,bool game,
	Player ana,Player opponent,Bag & bag,int cnt) {
    if (board.tiesCount() >= 100 || idx >= depth || cnt >= 2) {////////
        return huristicBoard(board);
        // mfrod azod 7aga hna huristic of board
    }
    long double ret = 0;
    Bag b = bag;
    for (int i = 0; i < S; ++i) {
        long double p;
        b = bag;// check for riham operator overloding
        if (game == 1) {
            p = radom_rack(b, opponent);
            Move move = huristicMoves(board, opponent, ana);
            if (move.switchMove) {
                bool ex = false;
                if (bag.bagLen() == 0)
                    ex = true;
                ret -= p * ProbabilisticSearch(idx + 1, board, 0,
                                               ana, opponent, b, cnt + ex
                );
            } else if (move.tiles.size() > 0) {
                change(b, opponent, move.tiles);
                ret -= p * ProbabilisticSearch(idx + 1, board, 0,
                                               ana, opponent, b, 0
                );
            } else {
                int score = J.applyMove(move, board, opponent, bag);
                ret -= p * (ProbabilisticSearch(idx + 1, board, 0,
                                                ana, opponent, b, 0
                ) + score);
            }
        } else {
            p = radom_rack(b, ana);
            Move move = huristicMoves(board, ana, opponent);
            if (move.switchMove) {
                bool ex = false;
                if (bag.bagLen() == 0)
                    ex = true;
                ret += p * ProbabilisticSearch(idx + 1, board, 0,
                                               ana, opponent, b, cnt + ex
                );
            } else if (move.tiles.size() > 0) {
                change(b, opponent, move.tiles);
                ret += ProbabilisticSearch(idx + 1, board, 0,
                                           ana, opponent, b, 0
                );

            } else {
                int score = J.applyMove(move, board, ana, bag);
                ret += p * (ProbabilisticSearch(idx + 1, board, 1,
                                                ana, opponent, b, 0
                ) + score);
            }
        }

    }
    return ret;
}

// ana mb3otly acctions klaha tnf3 tt3ml rihaaaaaaaaaaaaaaaaaam
Move nextPlay(const vector<Move>&plays, Board board, Bag bag , Player ana,Judge j ) {
    long double mx = -1e18;
    int playIdx = 0;
    J = j;
    int size = plays.size();
    for (int i = 0; i < plays.size(); ++i) {
        int score = J.applyMove(plays[i], board, ana, bag);
        Player opponent(2);/////for omnia
        // 1 for opponent ,0 for me
        long double expectedValue = ProbabilisticSearch(0, board,
                                                        1, ana, opponent, bag, 0) + score / 1.0 / size;
        if (mx < expectedValue) {
            mx = expectedValue;
            playIdx = i;
        }
    }
    return plays[playIdx];
}
