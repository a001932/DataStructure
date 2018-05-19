#include <iostream>
using namespace std;

int par(int a[], int l, int r)
{
	int pk = a[l];
	int p=l,q=r;

	while( p < q )
	{
		if(a[p] < pk) p++;
		if(a[q] > pk) q--;
		if(p < q ) swap(a[p],a[q]);
	}

	swap(a[l],a[q]);
	return q;
}


int select(int a[], int l1, int r1, int k1)
{
	int kth,pos;

	pos = par(a,l1,r1);
	kth = pos-l1+1;


	if(l1<r1)
	{
		if(kth == k1) return a[pos];
		else if(k1 < kth) return select(a,l1,pos-1,k1);
		else return select(a,pos+1,r1,k1-kth);
	}
	return a[pos];
}



int main()
{
	int a[8] = {1,2,3,4,5,6,7,8};
	int i,k;

	cout << "kth greatest/smallest num?" << endl;
	cin >> k;
		cout << k << "th greatest number is " << select(a,0,7,8-k+1) << endl;
		cout << k << "th smallest number is " << select(a,0,7,k) << endl;

	cout << endl;
}
