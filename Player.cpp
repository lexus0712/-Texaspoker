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
int Player::Compare(Poker bestArray[5],int whichcardarray[14])
{
	int whichcolor = 0;
	Poker temp=0;
	bool straight=false;
	int total[4] = { 0 };
	int straightcorrect=0;
	int repeatcard[8] = { 0 };
	for (int a = 0; a < 7; a++)//算重複的花色
	{
		if (bestArray[a].getCardcolor() == 0)
		{
			total[0]++;
		}
		else if (bestArray[a].getCardcolor() == 1)
		{
			total[1]++;
		}
		else if (bestArray[a].getCardcolor() == 2)
		{
			total[2]++;
		}
		else if (bestArray[a].getCardcolor() == 3)
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
				if (bestArray[i].getPokercard() > bestArray[j].getPokercard())
				{
					temp = bestArray[i];
					bestArray[i] = bestArray[j];
					bestArray[j] = temp;
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
	for (int l = 1; l < 14; l++)//看數字重複有幾張
	{
		int z = whichcardarray[l];
		repeatcard[z]++;
	}
	for (int k = 1; k < 14; k++)//順子迴圈;
	{
		if (whichcardarray[k] && whichcardarray[k + 1] && whichcardarray[k + 2] && whichcardarray[k + 3] && whichcardarray[k + 4]==1)
		{
			straight = true;
		}
	}
	if (total[whichcolor]== 5)//皇家同花順
	{
		if (straight)
		{
			if (whichcardarray[1] && whichcardarray[10] && whichcardarray[11] && whichcardarray[12] && whichcardarray[13] == 1)
			{
				WinOrLoseValue = 10;
				return WinOrLoseValue;
			}
		}
	}
	else if (total[whichcolor] == 5)//同花順
	{
		if (straight)
		{
			WinOrLoseValue = 9;
			return WinOrLoseValue;
		}
		
	}
	else if (repeatcard[4]>=1)//四條
	{
		WinOrLoseValue = 8;
		return WinOrLoseValue;
	}
	else if (repeatcard[3] >= 1&& repeatcard[2] == 1)//葫蘆
	{
		WinOrLoseValue = 7;
		return WinOrLoseValue;
	}
	else if (total[whichcolor] == 5)//同花
	{
		WinOrLoseValue = 6;
		return WinOrLoseValue;
	}
	else if (straight)//順子
	{
		WinOrLoseValue =5;
		return WinOrLoseValue;
	}
	else if (repeatcard[3]==1)//三條
	{
		WinOrLoseValue = 4;
		return WinOrLoseValue;
	}
	else if (repeatcard[2] >= 2)//兩對
	{
		WinOrLoseValue =3;
		return WinOrLoseValue;
	}
	else if (repeatcard[2] == 1)//一對
	{
		WinOrLoseValue = 2;
		return WinOrLoseValue;
	}
	else //高牌
	{
		WinOrLoseValue = 1;
		return WinOrLoseValue;
	}

}
int Player::Compare2(Poker bestArray[5], int WinOrLoseValue1, Computer& c1,int whichcardarray[14])
{		
	int max1 = 0;
	int max2 = 0;
	int max5 = 0;
	switch (WinOrLoseValue1)
	{
	case 1://比較誰的highcard大

		if (this->getFirstcard().getPokercard()>= this->getsecondcard().getPokercard())
		{
			max1 = this->getFirstcard().getPokercard();
		}
		else
		{
			max1 = this->getsecondcard().getPokercard();
		}
		if (c1.getCfirstcard().getPokercard() >= c1.getCsecondcard().getPokercard())
		{
			max2 = c1.getCfirstcard().getPokercard();
		}
		else
		{
			max2 =c1.getCsecondcard().getPokercard();
		}
		if (max1 > max2)return 1;//玩家贏
		else if(max1 < max2)return 0;//電腦贏
		else if (max1 == max2)return 2;//平手
	case 2:
		cout << "一對" << endl;
		for (int l = 1; l < 14; l++)//看數字重複2張是哪個數
		{
			if (whichcardarray[l] == 2)
			{
				max5 = l;
			}
		}
		if (max5 > c1.getthehigh())return 1;//玩家贏
		else if (max5 < c1.getthehigh())return 0;//電腦贏
		else if (max5 == c1.getthehigh())return 2;//平手
	case 3:
		cout << "兩對" << endl;
		for (int l = 1; l < 14; l++)//看數字重複2張是哪個數
		{
			if (whichcardarray[l] >= 2)
			{
				max5 = l;
			}
		}
		if (max5 > c1.getthehigh())return 1;//玩家贏
		else if (max5 < c1.getthehigh())return 0;//電腦贏
		else if (max5 == c1.getthehigh())return 2;//平手
	case 4:
		cout << "三條" << endl;
		for (int l = 1; l < 14; l++)//看數字重複3張是哪個數
		{
			if (whichcardarray[l] == 3)
			{
				max5 = l;
			}
		}
		if (max5 > c1.getthehigh())return 1;//玩家贏
		else if (max5 < c1.getthehigh())return 0;//電腦贏
		else if (max5 == c1.getthehigh())return 2;//平手
	case 5:
		cout << "順子" << endl;
		for (int l = 0; l < 5; l++)//看順子最大是哪個數
		{
			if (bestArray[l].getPokercard() >= max5)
			{
				max5 == bestArray[l].getPokercard();
			}
		}
		if (max5 > c1.getthehigh())return 1;//玩家贏
		else if (max5 < c1.getthehigh())return 0;//電腦贏
		else if (max5 == c1.getthehigh())return 2;//平手
	case 6:
		cout << "同花" << endl;
		for (int l = 0; l < 5; l++)//看順子最大是哪個數
		{
			if (bestArray[l].getPokercard() >= max5)
			{
				max5 == bestArray[l].getPokercard();
			}
		}
		if (max5 > c1.getthehigh())return 1;//玩家贏
		else if (max5 < c1.getthehigh())return 0;//電腦贏
		else if (max5 == c1.getthehigh())return 2;//平手
	case 7:
		cout << "葫蘆" << endl;
		for (int l = 1; l < 14; l++)//看數字重複3張是哪個數
		{
			if (whichcardarray[l] == 3)
			{
				max5 = l;
			}
		}
		if (max5 > c1.getthehigh())return 1;//玩家贏
		else if (max5 < c1.getthehigh())return 0;//電腦贏
		else if (max5 == c1.getthehigh())return 2;//平手
	case 8:
		cout << "鐵支" << endl;
		for (int l = 1; l < 14; l++)//看數字重複4張是哪個數
		{
			if (whichcardarray[l] >= 4)
			{
				max5 = l;
			}
		}
		if (max5 > c1.getthehigh())return 1;//玩家贏
		else if (max5 < c1.getthehigh())return 0;//電腦贏
		else if (max5 == c1.getthehigh())return 2;//平手
	case 9:
		cout << "同花順" << endl;
		for (int l = 0; l < 5; l++)//看順子最大是哪個數
		{
			if (bestArray[l].getPokercard() >= max5)
			{
				max5 = bestArray[l].getPokercard();
			}
		}
		if (max5 > c1.getthehigh())return 1;//玩家贏
		else if (max5 < c1.getthehigh())return 0;//電腦贏
		else if (max5 == c1.getthehigh())return 2;//平手
	case 10:
		cout << "皇家同花順" << endl;
		return 2;//平手
	}
}