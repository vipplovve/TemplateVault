#include <iostream>
using namespace std;
                            // time complexity = nlog(logn)
int main()                  //prints prime by removing non-primes
{
    int num,x=100;
    cin>>num;
    int arr[num];
    while(x>0)
    {
        arr[num]=0;
        x-=1;
    }
    for(int x=2;x<=num;x++)
    {
        if(arr[x]==0)
        {
            for(int y=2;y<=num;y+=x)
            arr[x]=1;
        }
    }

    for(int z=2;z<=num;z++)
    {
        if(arr[z]==0)
        cout<<z<<" ";
    }

    return 0;
}