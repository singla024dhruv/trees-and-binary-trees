#include <iostream>
#include <string>
using namespace std;
int in(char a)
{
    int j=a-'0';
    return j;
}
char ch(int j)
{
    char c='a'+j-1;
    return c;
}
int getCodes(string input,string output[10000])
{
    if(input.size()==0)

    { output[0]="";
        return 1;
    }
  
    int x=getCodes(input.substr(1),output);
    for(int i=0;i<x;i++)
    {
        output[i]=ch(in(input[0]))+output[i];

    }
    string result[10000];
    int y=0;
    if(input.size()>1)
    {
        if((in(input[0])*10+in(input[1]))<=26&&(in(input[0])*10+in(input[1]))>10)
    {
        y=getCodes(input.substr(2),result);
    }
    }
    for(int i=0;i<y;i++)
        {
            output[i+x]=ch((in(input[0])*10+in(input[1])))+result[i];
        }
    return x+y;
    
}
int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
