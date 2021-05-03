#include"Computer.h"
Computer::Computer()
{
	cfirstcard = Poker(1);
	csecondcard = Poker(1);
	cWinOrLoseValue = 0;
	high = 0;
}
Computer::Computer(Poker newfirstcard, Poker newsecondcard, int newWinOrLoseValue, int newhigh)
{
	cfirstcard = newfirstcard;
	csecondcard = newsecondcard;
	cWinOrLoseValue = newWinOrLoseValue;
	high = newhigh;
}
void Computer::setthehigh(int newhigh)
{
	high = newhigh;
}
int Computer::getthehigh()
{
	return high;
}
void Computer::setCfirstcard(Poker newcfirstcard)
{
	cfirstcard = newcfirstcard;
}
void Computer::setCsecondcard(Poker newcsecondcard)
{
	csecondcard = newcsecondcard;
}
void Computer::setCwinOrLoseValue(int newcWinOrLoseValue)
{
	cWinOrLoseValue = newcWinOrLoseValue;
}

Poker Computer::getCfirstcard()
{
	return cfirstcard;
}
Poker Computer::getCsecondcard()
{
	return csecondcard;
}
int Computer::getCwinOrLoseValue()
{
	return cWinOrLoseValue;
}
int Computer::CCompare(Poker publicArray[5])
{
	int whichcolor = 0;
	Poker temp = 0;
	bool straight = false;
	int total[4] = { 0 };
	int straightcorrect = 0;
	Poker cardArray[7] = { 0 };
	int whichcardarray[14] = { 0 };
	int repeatcard[8] = { 0 };
	cardArray[0] = cfirstcard;
	cardArray[1] = csecondcard;
	cardArray[2] = publicArray[0];
	cardArray[3] = publicArray[1];
	cardArray[4] = publicArray[2];
	cardArray[5] = publicArray[3];
	cardArray[6] = publicArray[4];

	for (int a = 0; a < 7; a++)//算重複的花色
	{
		if (cardArray[a].getCardcolor() == 0)
		{
			total[0]++;
		}
		else if (cardArray[a].getCardcolor() == 1)
		{
			total[1]++;
		}
		else if (cardArray[a].getCardcolor() == 2)
		{
			total[2]++;
		}
		else if (cardArray[a].getCardcolor() == 3)
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
		if (total[n] >= 5)
		{
			whichcolor = n;
		}
	}
	for (int a = 0; a < 7; a++)//看數字那些有幾張
	{
		int y = cardArray[a].getPokercard();
		whichcardarray[y]++;
	}
	for (int l = 1; l < 14; l++)//看數字重複有幾張
	{
		int z = whichcardarray[l];
		repeatcard[z]++;
	}
	for (int k = 1; k < 14; k++)//順子迴圈;
	{
		if (whichcardarray[k] && whichcardarray[k + 1] && whichcardarray[k + 2] && whichcardarray[k + 3] && whichcardarray[k + 4] >= 1)
		{
			straight = true;
		}
	}
	if (total[whichcolor] >= 5)//皇家同花順
	{
		if (straight)
		{
			straightcorrect = 0;
			for (int a = 0; a < 7; a++)
			{
				if (cardArray[a].getPokercard() == 13 && cardArray[a].getCardcolor() == whichcolor)
				{
					straightcorrect++;
				}
				if (cardArray[a].getPokercard() == 12 && cardArray[a].getCardcolor() == whichcolor)
				{
					straightcorrect++;
				}
				if (cardArray[a].getPokercard() == 11 && cardArray[a].getCardcolor() == whichcolor)
				{
					straightcorrect++;
				}
				if (cardArray[a].getPokercard() == 10 && cardArray[a].getCardcolor() == whichcolor)
				{
					straightcorrect++;
				}
				if (cardArray[a].getPokercard() == 1 && cardArray[a].getCardcolor() == whichcolor)
				{
					straightcorrect++;
				}
				if (straightcorrect == 5)
				{
					cWinOrLoseValue = 10;
					return cWinOrLoseValue;
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
				if (cardArray[a].getPokercard() == cardArray[a + 1].getPokercard() - 1 && cardArray[a + 2].getPokercard() - 2 && cardArray[a + 3].getPokercard() - 3 && cardArray[a + 4].getPokercard() - 4)
				{
					if (cardArray[a].getCardcolor() && cardArray[a + 1].getCardcolor() && cardArray[a + 2].getCardcolor() && cardArray[a + 3].getCardcolor() && cardArray[a + 4].getCardcolor() == whichcolor)
					{
						cWinOrLoseValue = 9;
						high = cardArray[a + 4].getPokercard();//同花順中最大的那個數
						return cWinOrLoseValue;
					}
				}
			}
		}

	}
	else if (repeatcard[4] >= 1)//四條
	{
		for (int l = 1; l < 14; l++)//看數字重複4張是哪個數
		{
			if (whichcardarray[l] >=4)
			{
				high = l;
			}
		}
		cWinOrLoseValue =8;
		return cWinOrLoseValue;
	}
	else if (repeatcard[3] >= 1 && repeatcard[2] >= 1)//葫蘆
	{
		for (int l = 1; l < 14; l++)//看數字重複3張是哪個數
		{
			if (whichcardarray[l] == 3)
			{
				high = l;
			}
		}
		cWinOrLoseValue =7;
		return cWinOrLoseValue;
	}
	else if (total[whichcolor] >= 5)//同花
	{
		int max3 = 0;
		for (int l = 1; l < 14; l++)
		{
			if (whichcardarray[l] >=1&&l>max3)
			{
				max3 = l;
				high = max3;
			}
		}
		cWinOrLoseValue =6;
		return cWinOrLoseValue;
	}
	else if (straight)//順子
	{
		for (int a = 0; a < 7; a++)
		{
			if (cardArray[a].getPokercard() == cardArray[a + 1].getPokercard() - 1 && cardArray[a + 2].getPokercard() - 2 && cardArray[a + 3].getPokercard() - 3 && cardArray[a + 4].getPokercard() - 4)
			{
				cWinOrLoseValue = 5;
				high = cardArray[a + 4].getPokercard();//順子中最大的那個數
				return cWinOrLoseValue;
			}
		}
	}
	else if (repeatcard[3] >= 1)//三條
	{
		for (int l = 1; l < 14; l++)//看數字重複3張是哪個數
		{
			if (whichcardarray[l] == 3)
			{
				high = l;
			}
		}
		cWinOrLoseValue =4;
		return cWinOrLoseValue;
	}
	else if (repeatcard[2] >= 2)//兩對
	{
		for (int l = 1; l < 14; l++)//看數字重複2張是哪個數
			{
				if (whichcardarray[l] == 2)
				{
					high = l;//較晚出現的對數字必定比較大
				}
			}
		cWinOrLoseValue =3;
		return cWinOrLoseValue;
	}
	else if (repeatcard[2] >= 1)//一對
	{
		for (int l = 1; l < 14; l++)//看數字重複2張是哪個數
		{
			if (whichcardarray[l] == 2)
			{
				high = l;
			}
		}
		cWinOrLoseValue =2;
		return cWinOrLoseValue;
	}
	else //高牌
	{
	int max4 = 0;
		for (int l = 1; l < 14; l++)
		{
			if (whichcardarray[l] >= 1 && l > max4)
			{
				max4 = l;
				high = max4;
			}
		}
		cWinOrLoseValue =1;
		return cWinOrLoseValue;
	}

}