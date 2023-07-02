#include <iostream>
using namespace std;

long long int EEA(long long int a, long long int b, int &x, int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }

    else
    {
        int p,q;

        long long int d = EEA(b, a%b, p,q);

        x = q;
        y = p - q*(a/b);

        return d;
    }
}

int main()
{
    long long int a,b;
    cin>>a>>b;

    int x,y;

    cout<<"GCD is : "<<EEA(a,b,x,y)<<endl;
    cout<<"Solution of Equation : -\nA"<<a<<" + B"<<b<<" = "<<EEA(a,b,x,y)<<" are : A = "<<x<<" & B = "<<y<<endl;

    return 0;
}