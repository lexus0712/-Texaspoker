#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include"Player.h"
#include"Computer.h"
using namespace std;
void cardname1(int cardname)//�P�Ϊ��W�r
{
	switch (cardname)
	{
	case 1:
		cout << "highcard" << endl;
		break;
	case 2:
		cout << "�@��" << endl;
		break;
	case 3:
		cout << "���" << endl;
		break;
	case 4:
		cout << "�T��" << endl;
		break;
	case 5:
		cout << "���l" << endl;
		break;
	case 6:
		cout << "�P��" << endl;
		break;
	case 7:
		cout << "��Ī" << endl;
		break;
	case 8:
		cout << "�K��" << endl;
		break;
	case 9:
		cout << "�P�ᶶ" << endl;
		break;
	case 10:
		cout << "�Ӯa�P�ᶶ" << endl;
		break;
	}
}
void pokercolor(int color)//���
{
		switch (color)
		{
		case 0:
			cout << "����";
			break;
		case 1:
			cout << "���";
			break;
		case 2:
			cout << "�R��";
			break;
		case 3:
			cout << "�®�";
			break;
		}
}
int main()
{
	int wlv = 0;
	int bet;
	cout << "��J���N��C���}�l�Ϋ�0����"<<endl;
	cin >> bet;
	while (bet != 0)
	{
		Poker cardArray[7] = {};
		Poker bestArray[5] = {};
		int newpokercard = 0;
		srand(time(0));
		int num[10] = {0};
		int j;
		for (int i = 0; i < 10; i++) {//�H���ͦ�1~52��������ƶüƨî������ƭ���
			do {
				num[i] = 1 + (rand() % 52);  
				for ( j = 0; j <i; j++)//�ϥ�num[j-1]�@�����e�w�ͦ����}�C�����A�åB�P��e�s�ͦ���num[i-1]����O�_����
				{    
					if (num[i] == num[j]) //�P�_���S����e���@��
					{
						i--;
						break;   //�Y�b���L�{�J�쭫�ơA�hbreak���}�ͦ��s�ü�
					}
				}   
			} while (j != i);
		}
		//for (int r = 0; r < 10; r++)//�Хd�P����
		//{
		//	cout << num[r] << endl;
		//}
		Poker p1card[2];
		Poker c1card[2];
		Poker publiccard[5];
		for (int r = 0; r < 2; r++)//�Хd�P����
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
		cout << "�z����P�� ";//�A����ܤ�P
		for (int g = 0; g < 2; g++)
		{
			cout << " " << p1card[g].getPokercard() << " ";
			pokercolor(p1card[g].getCardcolor());
			cardArray[g] = p1card[g];
		}
		cout << " ���P�� ";//��ܤ��P
		for (int a = 0; a < 5; a++)
		{
			cout << " " << publiccard[a].getPokercard() << " ";
			pokercolor(publiccard[a].getCardcolor());
			cardArray[a + 2] = publiccard[a];
		}
		cout << endl;
		for (int a = 0; a < 5; a++)
		{	
			cout << "�ѥ���k��5�i�զ��P��,�̥���1�̥k��7"<<endl;
			int number = 0;
			cin >> number;
			if (number >= 1 && number <= 7)
			{
				bestArray[a] = cardArray[number-1];
			}
			else
			{
				cout << "���~,�Э��s��J" << endl;
					a--;
			}
		}
		for (int a = 0; a < 5; a++)
		{
			cout << bestArray[a].getPokercard() << endl;;
		}
		int whichcardarray[14] = { 0 };
		for (int a = 0; a < 5; a++)//�ݼƦr���Ǧ��X�i
		{
			int y = bestArray[a].getPokercard();
			whichcardarray[y]++;
		}
		p1.setWinOrLoseValue(p1.Compare(bestArray, whichcardarray));//���a1�o�쪺�P��
		c1.setCwinOrLoseValue(c1.CCompare(publiccard));//�q���o�쪺�P��
		if (p1.getWinOrLoseValue() > c1.getCwinOrLoseValue())
		{
			cout << "���a��o�ӧQ" << endl;
			cout << "�A�եX�F";
			cardname1(p1.getWinOrLoseValue());
			cout << "�q���եX�F"; 
			cardname1(c1.getCwinOrLoseValue());
		}
		if (p1.getWinOrLoseValue() < c1.getCwinOrLoseValue())
		{
			cout << "�q����o�ӧQ" << endl;
			cout << "�q���եX�F";
			cardname1(c1.getCwinOrLoseValue());
			cout << "�A�եX�F";
			cardname1(p1.getWinOrLoseValue());
		}
		if (p1.getWinOrLoseValue() == c1.getCwinOrLoseValue())//��ۦP�P�ήɤ�j�p
		{
			wlv=p1.Compare2(bestArray, p1.getWinOrLoseValue(),c1, whichcardarray);
			if (wlv == 1)cout << "���aĹ" << endl;
			else if (wlv == 0)cout << "�q��Ĺ" << endl;
			else if (wlv == 2)cout << "����" << endl;
			
		}
		cout << "�q������P�� ";//�A����ܤ�P
		for (int g = 0; g < 2; g++)
		{
			cout << " " << c1card[g].getPokercard() << " ";
			pokercolor(c1card[g].getCardcolor());
		}
		cout << "��J���N��C���}�l�Ϋ�0����" << endl;
		cin >> bet;
	}
	if (bet == 0)
	{
		cout << "�C������" << endl;
	}
}