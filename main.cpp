#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include"Player.h"
#include"Computer.h"
using namespace std;
void cardname1(int cardname)//牌形的名字
{
	switch (cardname)
	{
	case 1:
		cout << "highcard" << endl;
		break;
	case 2:
		cout << "一對" << endl;
		break;
	case 3:
		cout << "兩對" << endl;
		break;
	case 4:
		cout << "三條" << endl;
		break;
	case 5:
		cout << "順子" << endl;
		break;
	case 6:
		cout << "同花" << endl;
		break;
	case 7:
		cout << "葫蘆" << endl;
		break;
	case 8:
		cout << "鐵支" << endl;
		break;
	case 9:
		cout << "同花順" << endl;
		break;
	case 10:
		cout << "皇家同花順" << endl;
		break;
	}
}
void pokercolor(int color)//花色
{
		switch (color)
		{
		case 0:
			cout << "梅花";
			break;
		case 1:
			cout << "方塊";
			break;
		case 2:
			cout << "愛心";
			break;
		case 3:
			cout << "黑桃";
			break;
		}
}
int main()
{
	int wlv = 0;
	int bet;
	cout << "輸入任意鍵遊戲開始或按0結束"<<endl;
	cin >> bet;
	while (bet != 0)
	{
		Poker cardArray[7] = {};
		Poker bestArray[5] = {};
		int newpokercard = 0;
		srand(time(0));
		int num[10] = {0};
		int j;
		for (int i = 0; i < 10; i++) {//隨機生成1~52之間的整數亂數並消除重複重複
			do {
				num[i] = 1 + (rand() % 52);  
				for ( j = 0; j <i; j++)//使用num[j-1]作為之前已生成的陣列成員，並且與當前新生成的num[i-1]比較是否重複
				{    
					if (num[i] == num[j]) //判斷有沒有跟前面一樣
					{
						i--;
						break;   //若在比對過程遇到重複，則break離開生成新亂數
					}
				}   
			} while (j != i);
		}
		//for (int r = 0; r < 10; r++)//創卡牌物件
		//{
		//	cout << num[r] << endl;
		//}
		Poker p1card[2];
		Poker c1card[2];
		Poker publiccard[5];
		for (int r = 0; r < 2; r++)//創卡牌物件
		{
			p1card[r].setPokercard(1 + num[r]%13);
			p1card[r].setCardcolor(num[r] / 13);
		}
		for (int g = 0; g < 2; g++)
		{
			c1card[g].setPokercard(1 + num[g+2]%13);
			c1card[g].setCardcolor(num[g + 2] / 13);
		}
		for (int b = 0; b < 5; b++)
		{
			publiccard[b].setPokercard(1 + num[b+4]%13);
			publiccard[b].setCardcolor(num[b + 4] / 13);
		}
		int WinOrLoseValue1 = 0;
		int WinOrLoseValue2 = 0;
		Player p1(p1card[0], p1card[1], WinOrLoseValue1);
		Computer c1(c1card[0], c1card[1], WinOrLoseValue2,0);
		cout << "您的手牌為 ";//你的顯示手牌
		for (int g = 0; g < 2; g++)
		{
			cout << " " << p1card[g].getPokercard() << " ";
			pokercolor(p1card[g].getCardcolor());
			cardArray[g] = p1card[g];
		}
		cout << " 公牌為 ";//顯示公牌
		for (int a = 0; a < 5; a++)
		{
			cout << " " << publiccard[a].getPokercard() << " ";
			pokercolor(publiccard[a].getCardcolor());
			cardArray[a + 2] = publiccard[a];
		}
		cout << endl;
		for (int a = 0; a < 5; a++)
		{	
			cout << "由左到右選5張組成牌組,最左為1最右為7"<<endl;
			int number = 0;
			cin >> number;
			if (number >= 1 && number <= 7)
			{
				bestArray[a] = cardArray[number-1];
			}
			else
			{
				cout << "錯誤,請重新輸入" << endl;
					a--;
			}
		}
		for (int a = 0; a < 5; a++)
		{
			cout << bestArray[a].getPokercard() << endl;;
		}
		int whichcardarray[14] = { 0 };
		for (int a = 0; a < 5; a++)//看數字哪些有幾張
		{
			int y = bestArray[a].getPokercard();
			whichcardarray[y]++;
		}
		p1.setWinOrLoseValue(p1.Compare(bestArray, whichcardarray));//玩家1得到的牌形
		c1.setCwinOrLoseValue(c1.CCompare(publiccard));//電腦得到的牌形
		if (p1.getWinOrLoseValue() > c1.getCwinOrLoseValue())
		{
			cout << "玩家獲得勝利" << endl;
			cout << "你組出了";
			cardname1(p1.getWinOrLoseValue());
			cout << "電腦組出了"; 
			cardname1(c1.getCwinOrLoseValue());
		}
		if (p1.getWinOrLoseValue() < c1.getCwinOrLoseValue())
		{
			cout << "電腦獲得勝利" << endl;
			cout << "電腦組出了";
			cardname1(c1.getCwinOrLoseValue());
			cout << "你組出了";
			cardname1(p1.getWinOrLoseValue());
		}
		if (p1.getWinOrLoseValue() == c1.getCwinOrLoseValue())//當相同牌形時比大小
		{
			wlv=p1.Compare2(bestArray, p1.getWinOrLoseValue(),c1, whichcardarray);
			if (wlv == 1)cout << "玩家贏" << endl;
			else if (wlv == 0)cout << "電腦贏" << endl;
			else if (wlv == 2)cout << "平手" << endl;
			
		}
		cout << "電腦的手牌為 ";//你的顯示手牌
		for (int g = 0; g < 2; g++)
		{
			cout << " " << c1card[g].getPokercard() << " ";
			pokercolor(c1card[g].getCardcolor());
		}
		cout << "輸入任意鍵遊戲開始或按0結束" << endl;
		cin >> bet;
	}
	if (bet == 0)
	{
		cout << "遊戲結束" << endl;
	}
}