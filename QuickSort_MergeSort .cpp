#include <iostream>
#include <limits>
using namespace std;
// for showing the value after sorting
int Qe = 7;
int Me =6;
int timee = 0;
void MergeArray(int a[], int p,int q, int m);
void MergeSort(int a[], int p, int q);



// This is Homework 7, including Merge sort & Quick sort

// HW7-1 : Merge sort
void MergeSort(int a[], int p, int q)
{   
    if (p<q)
    {
        int m = (p+q)/2;

        // Sort two sides seperately
        MergeSort(a,p,m);
        MergeSort(a,m+1,q);

        // Then merge
        MergeArray(a,p,q,m);
    }
}

void MergeArray(int a[], int p,int q, int m)
{
    int n1 = m-p+1;
    int n2 = q-m;

    // Let  L,R be the two array to sort & merge
    int * L = new int[n1];
    int * R = new int[n2];

    // fill the value in the array
    for (int i = 0; i < n1; i++)  L[i] = a[p+i]; 
    for (int i = 0; i < n2; i++)  R[i] = a[i+m+1]; 


    // dont know 
    L[n1] = 2147483647;
    R[n2] = 2147483647;

    // Merge the Run, sorting here
    int i = 0, j = 0;
    for (int k = p; k <= q; k++) 
    {
        if (L[i] <= R[j]) 
        {
            a[k] = L[i];
            i++;
        }
        else 
        {
            a[k] = R[j];
            j++;
        }
    }

    // show value after one merge
    cout << "第" << ++timee <<"次合併結果 : " << endl;
    for(int i=0;i<Me;i++) cout <<a[i] << " ";
  
    cout << endl << endl;
}


// HW7-2 : Quick sort, set pivot as the first element in the array
void QuickSort(int *a, int l, int r)
{
    int pivot = a[l];
    int p = l, q = r;

    cout << "pivot is : " <<pivot<<endl;
    // partition part
    while( p < q )
    {
        while(a[p] <= pivot)   p++; 
        while(a[q] > pivot)   q--; 
        if(p < q) swap(a[p],a[q]);
    }

    // show value
        for(int i=0;i<Qe;i++)
        cout <<a[i] << " ";
    cout <<endl <<endl;

    swap(a[l],a[q]);  


	if (l>=r) return;
    else    
	{
   		// recursivly solve the QuickSort
		QuickSort(a, l, q-1);
		QuickSort(a, q+1, r);
	}
 }


// HW_7
int main()
{
	// input the assign vector
	int Merge[6] = {20, 80, 40, 25, 60, 30};
	int Quick[7] = {15, 72, 58, 47, 20, 40, 10};

        cout << endl;

        // show the result in sorting step
		cout << "process of merge sort: " << endl;
        MergeSort(Merge,0,5);
        cout << endl;

		cout << "process of quick sort: " << endl;
        QuickSort(Quick,0,6);
        cout << endl;

	cout << endl;
}
