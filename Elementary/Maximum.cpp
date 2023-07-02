#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter three numbers:-";
    cin>>a>>b>>c;
    if(a>b)
    {
        if(a>c)
        {
            cout<<"The Largest of the three numbers is: "<<a;
        }
        else
            {cout<<"The Largest of the three numbers is: "<<c;}
    }
    if(b>c)
    {
        if(b>a)
        {
            cout<<"The Largest of the three numbers is: "<<b;
        }
        else
            {cout<<"The Largest of the three numbers is: "<<c;}

    }
    if(c>a)
    {
        if(c>b)
        {
            cout<<"The Largest of the three numbers is: "<<c;
        }
        else
            {cout<<"The Largest of the three numbers is: "<<b;}
    }
    cout<<endl;
    cout<<"Thanks For Using :)";
    cout<<"\n";
    system("Pause");

    return 0;
}