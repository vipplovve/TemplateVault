#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool endtimesort(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

vector<int> ActivitySelection(vector<pair<int,int>> d, int s)
{
    int i = 0, j;
    vector<int> a;

    a.push_back(i);

    for(int j = 1 ; j < s ; j++)
    {
        if(d[j].first >= d[i].second)
        {
            a.push_back(j);
            i = j;
        }
    }

    return a;
}

int main()
{
    int size;
    cin>>size;

    vector<pair<int,int>> data;

    int s,e;

    for(int x = 0 ; x < size ; x++)
    {
        cin>>s>>e;
        data.push_back(pair<int,int>(s,e));
    }

    sort(data.begin(), data.end(), endtimesort);

    vector<int> ans;

    ans = ActivitySelection(data,size);

    int count = ans.size();

    cout<<endl<<"Total No. of Activities Done are : "<<count<<endl<<endl;

    cout<<"Selected Activites are : - \n\n";

    for(auto i : ans)
        cout<<data[i].first<<' '<<data[i].second<<endl;

    return 0;
}