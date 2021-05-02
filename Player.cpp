#include"Player.h"
Player::Player()
{
	firstcard = Poker(1);
	secondcard = Poker(1);
	WinOrLoseValue = 0;
}
Player::Player(Poker newfirstcard, Poker newsecondcard, int newWinOrLoseValue)
{
	firstcard = newfirstcard;
	secondcard = newsecondcard;
	WinOrLoseValue = newWinOrLoseValue;
}
void Player::setFirstcard(Poker newfirstcard)
{
	firstcard = newfirstcard;
}
void Player::setsecondcard(Poker newsecondcard)
{
	secondcard = newsecondcard;
}
void Player::setWinOrLoseValue(int newWinOrLoseValue)
{
	WinOrLoseValue = newWinOrLoseValue;
}

Poker Player::getFirstcard()
{
	return firstcard;
}
Poker Player::getsecondcard()
{
	return secondcard;
}
int Player::getWinOrLoseValue()
{
	return WinOrLoseValue;
}
int Player::Compare(Poker publicArray[5])
{
	int whichcolor = 0;
	Poker temp;
	bool straight=false;
	int total[4] = { 0 };
	int straightcorrect=0;
	Poker cardArray[7];
	int whichcardarray[14];
	int repeatcard[8];
	cardArray[0] = firstcard;
	cardArray[1] = secondcard;
	cardArray[2] = publicArray[0];
	cardArray[3] = publicArray[1];
	cardArray[4] = publicArray[2];
	cardArray[5] = publicArray[3];
	cardArray[6] = publicArray[4];

	for (int a = 0; a < 7; a++)//算重複的花色
	{
		if (cardArray[a].getCardcolor == 0)
		{
			total[0]++;
		}
		else if (cardArray[a].getCardcolor == 1)
		{
			total[1]++;
		}
		else if (cardArray[a].getCardcolor == 2)
		{
			total[2]++;
		}
		else if (cardArray[a].getCardcolor == 3)
		{
			total[3]++;
		}
	}
	for (int n = 0; n < 4; n++)//排序
	{
		for (int i = 0; i < 7; i = i + 1)
		{
			for (int j = i + 1; j < 7; j = j + 1)
			{
				if (cardArray[i].getPokercard() > cardArray[j].getPokercard())
				{
					temp = cardArray[i];
					cardArray[i] = cardArray[j];
					cardArray[j] = temp;
				}
			}
		}
	}
	for (int n = 0; n < 4; n++)//重複的花色是什麼
	{
		if (total[n]>=5)
		{
			whichcolor = n;
		}
	}
	for (int a = 0; a < 7; a++)//看數字那些有幾張
	{
		whichcardarray[cardArray[a].getPokercard()]++;
	}
	for (int l = 1; l < 14; l++)//看數字重複有幾張
	{
		repeatcard[whichcardarray[l]]++;
	}
	for (int k = 1; k < 14; k++)//順子迴圈;
	{
		if (whichcardarray[k] && whichcardarray[k + 1] && whichcardarray[k + 2] && whichcardarray[k + 3] && whichcardarray[k + 4]>=1)
		{
			straight = true;
		}
	}
	if (total[whichcolor]>= 5)//皇家同花順
	{
		if (straight)
		{
			straightcorrect = 0;
			for (int a = 0; a < 7; a++)
			{
				if (cardArray[a].getPokercard() == 13 && cardArray[a].getCardcolor == whichcolor)
				{
					straightcorrect++;
				}
				if (cardArray[a].getPokercard() == 12 && cardArray[a].getCardcolor == whichcolor)
				{
					straightcorrect++;
				}
				if (cardArray[a].getPokercard() == 11 && cardArray[a].getCardcolor == whichcolor)
				{
					straightcorrect++;
				}
				if (cardArray[a].getPokercard() == 10 && cardArray[a].getCardcolor == whichcolor)
				{
					straightcorrect++;
				}
				if (cardArray[a].getPokercard()==1&& cardArray[a].getCardcolor== whichcolor)
				{
					straightcorrect++;
				}
				if (straightcorrect == 5)
				{
					WinOrLoseValue == 10;
					return WinOrLoseValue;
				}
			}
		}
	}
	else if (total[whichcolor] >= 5)//同花順
	{
		if (straight)
		{
			straightcorrect = 0;
			for (int a = 0; a < 7; a++)
			{
				if (cardArray[a].getPokercard()==cardArray[a+1].getPokercard()-1 && cardArray[a +2].getPokercard()-2 && cardArray[a+3].getPokercard()-3 && cardArray[a+4].getPokercard()-4)
				{
					if (cardArray[a].getCardcolor&&cardArray[a+1].getCardcolor&&cardArray[a+2].getCardcolor&&cardArray[a+3].getCardcolor&&cardArray[a+4].getCardcolor== whichcolor)
					{
						WinOrLoseValue == 9;
						return WinOrLoseValue;
					}
				}
			}
		}
		
	}
	else if (repeatcard[4]>=1)//四條
	{
		WinOrLoseValue == 8;
		return WinOrLoseValue;
	}
	else if (repeatcard[3] >= 1&& repeatcard[2] >= 1)//葫蘆
	{
		WinOrLoseValue == 7;
		return WinOrLoseValue;
	}
	else if (total[whichcolor] >= 5)//同花
	{
		WinOrLoseValue == 6;
		return WinOrLoseValue;
	}
	else if (straight)//順子
	{
		WinOrLoseValue == 5;
		return WinOrLoseValue;
	}
	else if (repeatcard[3]>=1)//三條
	{
		WinOrLoseValue == 4;
		return WinOrLoseValue;
	}
	else if (repeatcard[2] >= 2)//兩對
	{
		WinOrLoseValue == 3;
		return WinOrLoseValue;
	}
	else if (repeatcard[2] >= 1)//一對
	{
		WinOrLoseValue == 2;
		return WinOrLoseValue;
	}
	else //高牌
	{
		WinOrLoseValue == 1;
		return WinOrLoseValue;
	}

}
int Compare2(Poker publicArray[5], int WinOrLoseValue1)
{

}