#include <bits/stdc++.h>
using namespace std;

void print(string x) //to print the element sets of the ans vector.
{   cout<<"{ ";
    for(int a=0;a<x.length();a++)
    cout<<x[a]<<" ";
    cout<<"}\n";
}
void phonekeypad(string a,string output, vector<string> *ans,int index,string map[])
{
    if(index>=a.length()) //base condition.
    {
        ans->push_back(output);
        return;
    }

    int num=a[index]-'0';
    string substr=map[num]; //finding the mapping corresponding to the digits.

    for(int x=0; x<substr.length();x++) //recursive call + iterating through the elements.
    {
        output.push_back(substr[x]);
        phonekeypad(a,output,ans,index+1,map);
        output.pop_back();
    }
}
int main()
{
    string a;
    cout<<"Enter a Number Combination: ";
    cin>>a;
    string map[10]={"#","@","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int index=0;
    vector<string> ans;
    string output="";
    phonekeypad(a,output,&ans,index,map);
    for(int x=0;x<ans.size();x++)
    print(ans[x]);
    return 0;
}