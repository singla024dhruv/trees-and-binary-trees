#include <iostream>
using namespace std;
#include <cstring>
bool checkAB(char input[])
{
    
    int t=strlen(input);
    if(t==0)
    {
        return true;
    }
   if(t==1){if(input[0]=='b')
   {
       return false;
   }
   if(input[0]=='a')
   {
       return true;
   }
   }
   bool smalloutput=checkAB(input+1);
   if(smalloutput==false )
   {
       return false;
   }
   if(input[0]=='a'&&input[1]=='a')
   {
       return true;
   }
   if(input[0]=='a'&&input[1]=='b')
   {
       if(input[1]==input[2]&&input[3]=='a')
       {return true;
       }
   }
   return false;

}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
