#include"Poker.h"
Poker::Poker()
{
	pokercard = 0;
	cardcolor = 0;
}
Poker::Poker(int cardnum)
{
	//srand(time(0));
	//pokercard =  1 + (rand() % 52);
	cardcolor = pokercard / 13;
}
void Poker::setPokercard(int newpokercard)
{
	pokercard = newpokercard;
}

int Poker::getPokercard()
{
	return pokercard;
}
void Poker::setCardcolor(int newcardcolor)
{
	cardcolor = newcardcolor;
}

int Poker::getCardcolor()
{
	return cardcolor;
}
