#include <bits/stdc++.h>
using namespace std;

void saythem(int num,string map[])
{
    if(num==0)
    ;
    else{
        saythem(num/10,map);
        cout<<map[num%10]<<' ';
    }
}

int main()
{
    int n;
    cout<<"Enter an Integral Number Greater than Zero: ";
    cin>>n;
    string map[10]={"Shunya","Ek","Do","Teen","Char","Panch","Chey","Sat","Ath","No"};
    saythem(n,map);
    return 0;
}