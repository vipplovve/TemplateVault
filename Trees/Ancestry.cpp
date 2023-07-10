#include <bits/stdc++.h>
using namespace std;

int in[100000], out[100000];
int t;

void DFS(vector<vector<int>> d, int r, int v)
{
    t++;

    in[r] = t;

    for(auto x : d[r])
    {   
        if(x != v)
            DFS(d,x,r);
    }

    t++;
    
    out[r] = t;
}

int main()
{
    int nodes;

    cin >> nodes;

    vector<vector<int>> data(nodes, vector<int> ());

    int a[nodes], b[nodes];

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        cin >> a[x] >> b[x];
    }

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        data[a[x]-1].push_back(b[x]-1);
    }

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        data[b[x]-1].push_back(a[x]-1);
    }
    
    DFS(data,8,-1);

    int childA, childB;

    cin >> childA >> childB;

    childA--;
    childB--;

    bool condition = (in[childA] > in[childB] && out[childA] < out[childB]);

    if(condition)
        cout << "Yes, " << childB + 1 << " is the Ancestor of " << childA + 1 << '.' << endl;
    
    else
        cout << "No, " << childB + 1 << " isn't the Ancestor of " << childA + 1 << '.' << endl;

    return 0;
}