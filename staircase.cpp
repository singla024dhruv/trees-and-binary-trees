#include <iostream>
using namespace std;
int staircase(int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    int ans1,ans2,ans3;
    
    
   ans1=staircase(n-1);
     ans2=staircase(n-2);
     ans3=staircase(n-3);

  return ans1+ans2+ans3;
}
int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
