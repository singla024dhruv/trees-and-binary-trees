#include <iostream>
#include <string>

using namespace std;
int keyPad(int n,string mapping[],string output[])
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
    
    int smalloutput=keyPad(n/10,mapping,output);
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
int keypad(int n,string output[])
{
    string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int w= keyPad(n,mapping,output);
    return w;
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
