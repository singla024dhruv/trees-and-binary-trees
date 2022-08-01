/* to write code for  keypad dial*/
#include <iostream>
using namespace std;

int keypad(int n,string mapping[],string output[])
{
    if(n==0)
    {
        output[0]=mapping[0];
        return 1;
    }
    if(n==1)
    {
        output[0]=mapping[1];
        return 1;
    }
    
    int smalloutput=keypad(n/10,mapping,output);
    int t=n%10;
    string small=mapping[t];
    string* secoutput=new string[10000];
    int x=small.size();
    
    int j=0;

     for(int i=0;i<smalloutput;i++)

    {
        int e=0;
       while(e<x)
       {
             
           secoutput[j++]=output[i]+small[e];
           
          e++;
       }
       
    }
    for(int c=0;c<j;c++)
    {
        output[c]=secoutput[c];
    }
    return j;

}
int main()
{
    int n;
    string* output=new string[1000000];
    cin>>n;
    
    string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int count= keypad(n,mapping,output);
    for(int i=0;i<count;i++)
    {
        cout<<output[i]<<endl;
    }
}