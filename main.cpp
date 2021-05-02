#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include"Player.h"
using namespace std;

int main()
{
	int cardArray[9];
	int money = 10000;
	int bet;
	cout << "您現有資金" <<money << endl;
	cout << "輸入賭金遊戲開始或按0結束"<<endl;
	cin >> bet;
	while (bet != 0)
	{
		Poker p1card[2];
		Poker p2card[2];
		Poker publiccard[5];
		for (int r = 0; r < 2; r++)
		{
			p1card[r] = Poker(r);
		}
		for (int g = 0; g < 2; g++)
		{
			p2card[g] = Poker(g+2);
		}
		for (int b = 0; b < 5; b++)
		{
			publiccard[b] = Poker(b + 4);
		}
		int WinOrLoseValue1 = 0;
		int WinOrLoseValue2 = 0;
		Player p1(p1card[0], p1card[1], WinOrLoseValue1);
		Player p2(p2card[0], p2card[1], WinOrLoseValue2);
		p1.setWinOrLoseValue(p1.Compare(publiccard));//玩家1得到的牌形
		p2.setWinOrLoseValue(p2.Compare(publiccard));//玩家2得到的牌形
		if()
	}
	if (bet == 0)
	{
		cout << "遊戲結束" << endl;
	}
}