#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
#include"Player.h"
#include"Computer.h"
using namespace std;
int main()
{

	string cardsname[] = { "highcard" ,"一對","兩對","三條" ,"順子", "同花", "葫蘆", "鐵支" ,"同花順" , "皇家同花順" };
	//牌形的名字
	string suits[] = { "梅花", "方塊", "愛心", "黑桃" };
	string ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9",
	  "10", "Jack", "Queen", "King" };
	int wlv = 0;
	int bet;
	cout << "輸入數字遊戲開始或按0結束"<<endl;
	cin >> bet;
	while (bet != 0)
	{
		Poker cardArray[7] = {};
		Poker bestArray[5] = {};
		int newpokercard = 0;
		srand(time(0));
		//const int NUMBER_OF_CARDS = 52;
		//int num[NUMBER_OF_CARDS]={0};
		int num[10] = {0};
		int j;
		/*for (int i = 0; i < NUMBER_OF_CARDS; i++)
		{
			num[i] = i;
		}

		for (int i = 0; i < NUMBER_OF_CARDS; i++)
		{
			int index = rand() % NUMBER_OF_CARDS;
			int temp = num[i];
			num[i] = num[index];
			num[index] = temp;
		}*/
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
		cout << "您的手牌如下: ";//你的顯示手牌
		for (int g = 0; g < 2; g++)
		{
			cout << g + 1 << ". ";
			cout  << ranks[p1card[g].getPokercard()] << " ";
			cout<<suits[p1card[g].getCardcolor()];
			cout << " ";
			cardArray[g] = p1card[g];
		}
		cout << " 公牌如下: ";//顯示公牌
		for (int a = 0; a < 5; a++)
		{
			cout << a+3 << ". ";
			cout<< ranks[publiccard[a].getPokercard()] << " ";
			cout << suits[publiccard[a].getCardcolor()];
			cout << " ";
			cardArray[a + 2] = publiccard[a];
		}
		cout << endl;
		cout << endl;
		cout << "手牌+公共牌共7張,輸入數字選擇你要的牌, 組成5張牌的牌組（可選5次）" << endl;
		cout << ",最左側編號為1到最右側編號為7,由左到右卡牌的編號從編號1到編號7" << endl;
		for (int a = 0; a < 5; a++)
		{	
			cout <<endl;
			cout << "輸入編號選擇撲克牌（剩餘還可選"<<5-a<<"次）" << endl;
			int number = 0;							//總共7張牌從其中選出5張組成牌組
			cin >> number;						
			if (number >= 1 && number <= 7)		//輸入數字選擇你要的牌
			{
				bestArray[a] = cardArray[number-1];
			}
			else
			{
				cout << "錯誤,請重新輸入" << endl;
					a--;
			}
			cout << "目前牌組：";
			for (int g = 0; g < 5; g++)
			{
				cout << " " << ranks[bestArray[g].getPokercard()] << " ";
				cout << suits[bestArray[g].getCardcolor()];
			}
		}
		cout << endl;
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
			cout<<cardsname[p1.getWinOrLoseValue()];
			cout << "電腦組出了"; 
			cout << cardsname[c1.getCwinOrLoseValue()];
		}
		if (p1.getWinOrLoseValue() < c1.getCwinOrLoseValue())
		{
			cout << "電腦獲得勝利" << endl;
			cout << "電腦組出了";
			cout << cardsname[c1.getCwinOrLoseValue()];
			cout << "你組出了";
			cout << cardsname[p1.getWinOrLoseValue()];
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
			cout << " " << ranks[c1card[g].getPokercard()] << " ";
			suits[c1card[g].getCardcolor()];
		}
		cout << endl;
		cout << "輸入任意數字遊戲開始或按0結束" << endl;
		cin >> bet;
	}
	if (bet == 0)
	{
		cout << "遊戲結束" << endl;
	}
}
