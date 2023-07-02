#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    else
    return (fibonacci(n-1)+fibonacci(n-2));

}

int main()
{
    for(int x=0;x<5;x++)
    cout<<fibonacci(x)<<endl;
    return 0;
}

//Same function can be used to calculate number of distinct ways to reach nth stair from 0th stair given that you can take 1 or two steps at a time.