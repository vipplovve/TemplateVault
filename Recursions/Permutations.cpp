#include <bits/stdc++.h>
using namespace std;


void permutations(string input,vector<string> &ans,int index)
{
    if(index>=input.size())
    {
        ans.push_back(input);
        return;
    }
    for(int x=index;x<input.size();x++)
    {
        swap(input[index],input[x]);
        permutations(input,ans,index+1);
        swap(input[index],input[x]);
    }
}
int main()
{
    string input;
    cout<<"Enter a Sequence: ";
    cin>>input;
    vector<string> ans;
    int index=0;
    permutations(input,ans,index);
    cout<<"There are total "<<ans.size()<<" Possible Permutations: -\n";
    sort(ans.begin(),ans.end());
    for(int x=0;x<ans.size();x++)
    {   cout<<"{ ";
        for(int y=0;y<input.length();y++)
        cout<<ans[x][y]<<" ";
        cout<<"}";
        cout<<endl;
    }
    return 0;
}