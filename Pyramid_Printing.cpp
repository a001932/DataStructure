#include<iostream>
using namespace std;
int main()
{
	int height,space;
	int i,num=0;
	cin >> height;

	for(i=1;i<=height;i++)
	{
		// 空白的部分＝高度-i(用觀察的)
		for(space = i ;space <= height-1;space++)
			cout << " ";

		// num要小於，有等於會多做一次
		while(num < 2*i-1)
		{
			cout << "*";
			num++;
		}
		cout << endl;
		num = 0;
	}
}