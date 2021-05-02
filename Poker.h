#ifndef POKER_H
#define POKER_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

class Poker
{
private:
	int pokercard;
	int cardcolor;
public:
	Poker();
	Poker(int);
	void setPokercard(int);
	int getPokercard();
	void setCardcolor(int);
	int getCardcolor();
};
#endif
