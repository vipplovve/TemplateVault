#include <iostream>
using namespace std;
int main()
{
    int x,y;
    char o;
    cout<<"Enter Two Numbers: ";
    cin>>x>>y;
    cout<<"Enter Operation: ";
    cin>>o;
    switch(o)
    {
        case '+':
            cout<<x<<'+'<<y<<'='<<x+y;
            break;
        case '-':
            cout<<x<<'-'<<y<<'='<<x-y;
            break;
        case '*':
            cout<<x<<'*'<<y<<'='<<x*y;
            break;
        case '/':
            cout<<x<<'/'<<y<<'='<<x/y;
            break;
        case '%':
            cout<<x<<'%'<<y<<'='<<x%y;
            break;
    }
    return 0;
}