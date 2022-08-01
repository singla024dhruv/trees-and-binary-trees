#include <iostream>
using namespace std;
void helper(int input[],int size,int k,int output[],int m)
{
    if(size==0)
    {
        if(k==0||k>0)
        {
            for(int q=0;q<m;q++)
            {
                cout<<output[q];
            }
            cout<<endl;
        }
        if(k<0||k>0)
        {
            return;
        }

    }
    int newoutput[10000];
    for(int e=0;e<m;e++)
    {
        if(e==0)
        {
            newoutput[e]=1+output[e];
        }
        newoutput[1]=input[0];
        

    }
     helper(input+1,size-1,k,output,m);
    helper(input+1,size-1,k-input[0],newoutput,m+1);
}
void printSubsetSumToK(int input[], int size, int k)
{
   int output[10000];
   int m=0;
   helper(input,size,k,output,m);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
