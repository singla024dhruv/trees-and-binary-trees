#include <iostream>

using namespace std;
int helperfunction(int input[],int si,int ei,int element)
{
    if(si>ei)
    {
        return -1;
    }
    int mid =(si+ei)/2;
    if(input[mid]==element)
    {
        for(int i=si;i<mid;i++)
        {
            if(input[i]==element)
            {
                return i;
            }
        }
        return mid;
    }
     if(input[mid]<element)
    {
         return helperfunction(input,mid+1,ei,element);

    }
    else if(input[mid]>element)
    {
       return helperfunction(input,si,mid-1,element);
    }
     
    return -1;
    

}
int binarySearch(int input[], int size, int element)
{
    int si=0;
    int ei=size-1;
    return helperfunction(input,si,ei,element);
}
int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
