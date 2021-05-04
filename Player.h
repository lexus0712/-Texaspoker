#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <iomanip>
#include"Poker.h"
#include"Computer.h"
using namespace std;
class Player
{
private:
	Poker firstcard;
	Poker secondcard;
	int WinOrLoseValue;
public:
	Player();
	Player(Poker, Poker,int);
	void setFirstcard(Poker);
	void setsecondcard(Poker);
	void setWinOrLoseValue(int);
	Poker getFirstcard();
	Poker getsecondcard();
	int getWinOrLoseValue();
	int Compare(Poker publicArray[5],int whichcardarray[14]);
	int Compare2(Poker publicArray[5], int, Computer &c1, int whichcardarray[14]);
};
#endif