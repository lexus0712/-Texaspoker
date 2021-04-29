#include <iostream>
#include <sstream>
#include <string>
using namespace std;
void printStringArray(string word[], int size)
{
	for (int a = 0; a < size; a++)
	{
		cout << word[a] << endl;
	}

}
int main()
{
	string a1;
	getline(cin, a1);
	int count = 0;
	string word[10] ;
	stringstream ss(a1);
	while (!ss.eof())
	{
		ss >> word[count];
		
		count++;

	}
	printStringArray( word,  count);
	cout<< "Length:"<<a1.length()<<endl;
	int as=a1.length();
	cout<<a1.insert(as,3,'!');
}
