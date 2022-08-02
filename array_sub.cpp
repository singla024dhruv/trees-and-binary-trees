#include <bits/stdc++.h>
#include <string>
using namespace std;
/*int helper(int input[],int si,int n,int output[][20])
{
    if(si==n)
    {
        output[0][0]=0;
        return 1;
    }
    int ans=helper(input,si+1,n,output);
    int c;
    for (int i = 0; i < ans; i++)
    {
        c=output[i][0];
        output[i+ans][0]=1+c;
        for(int j=1;j<=c;j++)
        {
            output[i+ans][j+1]=output[i+ans][j];
        }
        output[i+ans][1]=input[si];


        
    }
    return 2*ans;
    
}*/
int subset(int input[], int n, int output[][20]) 
{
    if(n==0)
    {
        output[0][0]=0;
        return 1;
    }
    int ans =subset(input+1,n-1,output);
    
    for (int i = 0; i < ans; i++)
    {
        int c;
        c=output[i][0];
        output[i+ans][0]=1+c;
        output[i+ans][1]=input[0];
        for(int j=1;j<=output[i][0];j++)
        {
            output[i+ans][j+1]=output[i][j];
        }
       // output[i+ans][1]=input[0];
    }
    return 2*ans;
    
    
    
}
int main()
 {
  int input[20];
  int length;
  int output[35000][20];
  cin>>length;
  for(int i=0; i < length; i++)
    {
        cin>>input[i];
    }
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
