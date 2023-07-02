#include <iostream>
using namespace std;

int main()
{
    int x;
    cout<<"Enter a Number: ";
    cin>>x;
    if(x>0)
    {
        cout<<"The entered number is a positive one.";
    }
    if(x<0)
    {
        cout<<"The entered number is a negative one.";
    }
    if(x=0)
    {
        cout<<"The entered number is zero.";
    }

    return 0;
}