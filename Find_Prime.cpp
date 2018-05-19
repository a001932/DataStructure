#include<iostream>
using namespace std;


bool sure (int p)
{
	if (p==1) return false;
	while(p > 1)
	{
		if(p%2==0)
			p/=2;
		else if(p%3==0)
			p/=3;
		else 
			return false;
	}

	return true;
}


int main()
{
    int n;
    int i,count=0;

    cin >> n;
    int p = n;
    i = 2;
    while( p > 1 )
    {
        while( p%i == 0 )
        {
            cout << i << " ";      	
        	p /=i;  
        }
        i = i+1;
    }
    cout << endl;


    int num = 1;
    while( num < n )
    {
    	if(sure(num))
    	{
    		//cout << num << " ";
    	    count++;    		
    	}

    	num++;
    }

    //cout << endl << "一共有" << count << "個" << endl;



    return 0;
}
