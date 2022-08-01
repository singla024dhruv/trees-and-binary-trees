#include <iostream>
using namespace std;
int helper(int input[],int si,int n,int output[][50],int k)
{
    if(si==n)
    {
        if(k==0)
        {
            output[0][0]=0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int o1[1000][50];
    int o2[1000][50];
    int x=helper(input,si+1,n,o1,k-input[si]);
    int y=helper(input,si+1,n,o2,k);
    int row=0;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<=o1[i][0];j++)
        {
            if(j==0)
            {
                output[row][j]=1+o1[i][j];
                
            
            }
            if(j==1)
            {
                output[row][j]=input[si];
                
            
            }
            else
            {
                output[row][j]=o1[i][j-1];
                          

            }
        }
        ++row;
    }
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<=o2[i][0];j++)
        {
            output[row][j]=o2[i][j];
            
        }
        ++row;
    }
    return row;
}
int subsetSumToK(int input[], int n, int output[][50], int k)
{
    int si=0;
    return helper(input,si,n,output,k);
}
int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
