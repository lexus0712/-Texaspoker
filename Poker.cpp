#include"Poker.h"
Poker::Poker()
{
	pokercard = 0;
	cardcolor = 0;
}
Poker::Poker(int newpokercard)
{
	cardcolor = newpokercard / 13;
	pokercard = newpokercard;
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
