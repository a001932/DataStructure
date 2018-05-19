#include <iostream>
using namespace std;

//this .cpp file include HW2-1 & HW2-2

// function for HW2-1
double average(int b[], int i ,int l)　
{
	if (i+1 == l)
		return ((b[i] + average(b,i-1,l))/l);	
	else if (b[i])
		return b[i] + average(b,i-1,l);
	else 
		return 0;
}


// function for HW2-2

int par(int b[], int l, int r, int lim)
{
	int pk = lim;
	int p=l,q=r;

	while( p < q )
	{
		if(b[p] <= pk) p++;
		if(b[q] > pk) q--;
		if (p < q) swap(b[p],b[q]);
	}
	return p;
}

int section(int a[], int start, int end ,int bound)
{
	int pos = par(a, start, end, bound);
	if (bound < 110)
	{
		if (bound < 100)
		{
			cout << bound - 9 << "~" << bound << " ： "; 
			if (start != pos)
			{
				for (int i = start ; i < pos ; i++)
				{
					cout << a[i] << " ";
				}
			}
			cout << endl;
			return section(a, pos, end, bound+10);
		}

	// range > 100
		else
		{
			cout << "above 100 ： "; 
			for (int i = start ; i < end ; i++)
				cout << a[i] << " ";
			cout << endl;
		}
	}
	
}

int main(void)
{
	// HW2-1 find the average through recursive function
	int aBag[10] = {11,87,34,53,46,92,75,28,69,100};
	int length = sizeof(aBag)/sizeof(*aBag);
	cout << "HW2-1 answer is " << average(aBag, length-1 ,length) << endl << endl;


	// HW2-2 display data in different section by quick select 
	// Through quick select to find the index of each section then display
	int Bag[20] = {13,27,35,87,61,44,101,25,18,52,74,98,69,48,110,23,38,10,125,88};
	int tail = sizeof(Bag)/sizeof(*Bag)-1;
	cout << "HW2-2 answer is " << endl << section(Bag, 0, tail, 9) << endl;
}	

