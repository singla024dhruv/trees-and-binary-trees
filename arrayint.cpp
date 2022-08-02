/*to find intersection of array with bettter time complexity*/
#include <iostream>
using namespace std;
void mergesort(int *input,int si,int mid,int ei)
{
    int n1=mid-si+1;
    int n2=ei-mid;
    int *a1=new int[n1];
    int *a2=new int[n2];
    for(int i=0;i<n1;i++)
    {
        a1[i]=input[si+i];
    }
    for(int i=0;i<n2;i++)
    {
       a2[i]=input[mid+1+i];
    }
    int i=0;
    int j=0;
    int t=0;
    while(i<n1&&j<n2)
    {
        if(a1[i]>=a2[j])
        {
           input[t++]=a2[j];
           j++;
        }
        else 
        {
            input[t++]=a1[i];
            i++;
        }
    }
    while(i<n1)
    {
        input[t++]=a1[i];
        i++;
    }
    while(j<n2)
    {
        input[t++]=a2[i];
        j++;
    }
    delete []a1;
    delete []a2;
    return ;
}
void helper(int *input,int si,int ei)
{
    if(si>=ei)
    {
        return ;
    }
    int mid=(si+ei)/2;     
    helper(input,si,mid);
    helper(input,mid+1,ei);
    mergesort(input,si,mid,ei);   //call for merge sort
}
void sort(int *input,int n)
{
   int si=0; //apply merge sort
   int ei=n-1;
   helper(input,si,ei);
}
void intersection(int *arr1,int *arr2,int n,int m)
{
    sort(arr1,n);
    sort(arr2,m);
    int i=0;
    int j=0;
    while(i<n&&j<m)
    {
        if(arr1[i]<arr2[j])
        {
            i++;

        }
        else if(arr1[i]>arr2[j])
        {
            j++;
        }
        else
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}