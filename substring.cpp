/*to find the subsequence of the string*/
#include <iostream>
using namespace std;
int subs(string input,string output[])   //function declaration
{
    if(input.empty())
    {
        output[0]= "";
        return 1;
    }
    string smallstring=input.substr(1);
    int smalloutput=subs(smallstring,output);  //recursion call
    for(int i=0;i<smalloutput;i++)   
    {
        output[i+smalloutput]=input[0]+output[i];
    }
  return 2*smalloutput;

}
int main()
{
    string input;
    cout<<"enter string";
    getline(cin,input);
    string* output=new string[1000];   //dynamic declaration
    int count=subs(input, output);    //function call
    for(int i=0;i<count;i++)
    {
        cout<<output[i]<<endl;
    }
     
}