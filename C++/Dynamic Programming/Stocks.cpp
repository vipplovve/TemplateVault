#include <bits/stdc++.h>
using namespace std;

int main()
{
    int days;

    cin>>days;

    int data[days];

    for(int x = 0 ; x < days ; x++)
        cin>>data[x];

    int mini = data[0];

    int profit = -1;

    for(int x = 0 ; x < days ; x++)
    {
        profit = max(profit,data[x] - mini);
        mini = min(data[x],mini);
    }

    cout<<"Max Profit That Can Be Generated is : "<<profit<<endl;
}