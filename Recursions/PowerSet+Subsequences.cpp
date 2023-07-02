#include <bits/stdc++.h>
using namespace std;

void print(vector<char>v) 
{
    int len=v.size();
    for(int x=0;x<len;x++)
    cout<<v[x]<<' ';
}
void powerset(vector<char> v,vector<char> output, int index, vector<vector<char>> *a) 
{
    if(index>=v.size())
    {   
        a->push_back(output);
        return ;
    }

    powerset(v,output,index+1,a);
    char value=v[index];
    output.push_back(value);
    powerset(v,output,index+1,a);
}

int main()
{
    int len;
    cout<<"Enter Length: ";
    cin>>len;
    vector<char> v;
    vector<char> output;
    vector<vector<char>>a;
    cout<<"Input the Set: ";
    for(int x=0;x<len;x++) 
    {
        char num;
        cin>>num;
        v.push_back(num);
    }

    powerset(v,output,0,&a);
    int x=a.size();
    cout<<"Printing the Power Set Elements "<<"(Which are "<<x<<" in total): - \n";
    for(int i=0;i<x;i++)
    {
        cout<<"{ ";
        print(a[i]);
        cout<<"}";
        cout<<endl;
    }
    return 0;
}

//using character datatype since it will work with digits as well as characters.