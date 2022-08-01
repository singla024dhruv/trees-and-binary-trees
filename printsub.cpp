#include <iostream>
using namespace std;
void helper(int input[],int size,int output[],int m)
{
    if(size==0)
    {
        
        for(int i=0;i<m;i++)
        {
            cout<<output[i]<<" ";
            
        }
        cout<<endl;
        return;
    }
    
    int newout[35000];
    
    for(int i=0;i<m;i++)
    {
        newout[i]=output[i];
    }
    newout[m]= input[0];
     helper(input+1,size-1,output,m);
    helper(input+1,size-1,newout,m+1);
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[35000];
    int m=0;
    helper(input,size,output,m);
    
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
