#include <bits/stdc++.h>
using namespace std;

int in[200001], out[200001];

vector<vector<long long>> tree;

int t;

void DFS(int r, int v)
{
    t++;

    in[r] = t;

    for(auto x : tree[r])
    {   
        if(x != v)
            DFS(x,r);
    }

    t++;
    
    out[r] = t;
}

int main()
{
    int nodes;

    cin >> nodes;

    tree.assign(200001,vector<long long>());

    int a,b;

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        cin >> a >> b;

        tree[a].push_back(b);

        tree[b].push_back(a);
    }

    for(int x = 1 ; x < nodes + 1 ; x++)
    {
        cout << "Nodes Connected With " << x << " : ";

        for(int y = 0 ; y < tree[x].size() ; y++)
            cout << tree[x][y] << ' ';
        
        cout << endl;
    }

    int root;

    cin >> root;

    DFS(root,0);

    int childA, childB;

    cin >> childA >> childB;

    bool condition = (in[childA] > in[childB] && out[childA] < out[childB]);

    if(condition)
        cout << endl << "Yes, " << childB << " is the Ancestor of " << childA << '.' << endl;
    
    else
        cout << endl << "No, " << childB << " isn't the Ancestor of " << childA << '.' << endl;

    return 0;
}