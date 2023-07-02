#include <iostream>
using namespace std;
int main()
{
    int x,y,i,num;
    cout<<"Enter Two Numbers: ";
    cin>>x>>y;
    for(i=x;i<=y;i++)
    {
        for(num=2;num<=i-1;num++)
        {
            if(i%num==0)
            {
                break;
            }
        }
        if(num==i)
        cout<<i<<" Is a Prime Number\n";
    }
    return 0;
}