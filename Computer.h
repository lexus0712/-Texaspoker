#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <iomanip>
#include"Poker.h"
using namespace std;
class Computer
{
private:
	Poker cfirstcard;
	int high;
	Poker csecondcard;
	int cWinOrLoseValue;
public:
	Computer();
	Computer(Poker, Poker, int,int);
	void setCfirstcard(Poker);
	void setCsecondcard(Poker);
	void setthehigh(int);
	void setCwinOrLoseValue(int);
	int getthehigh();
	Poker getCfirstcard();
	Poker getCsecondcard();
	int getCwinOrLoseValue();
	int CCompare(Poker publicArray[5]);
};
#endif