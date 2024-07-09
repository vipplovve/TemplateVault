#include <iostream>
#include <algorithm>

using namespace std;

void FittingShelves(int a, int b, int c)
{
    int m = 0, n = 0, leftout = c;

    int x = c/a;
    int y = 0; 
    int r = c%a;

    while(c >= b)
    {
        y++;

        c = c - b;

        x = c/a;
        r = c%a;

        if(r<leftout)
        {
            m = x;
            n = y;
            leftout = r;
        }
    }

    cout<<"We Require "<<m<<" No. of Item #1.\n"<<n<<" No. of Item #2.\nThe Remaining Space Left would be : "<<leftout<<endl;
}

int main()
{
    int a,b,c;

    cin>>c;
    cin>>a>>b;

    FittingShelves(a,b,c);

    return 0;
}