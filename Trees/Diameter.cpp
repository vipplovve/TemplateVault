#include <bits/stdc++.h>
using namespace std;

vector<int> lvls;
vector<vector<int>> tree;

void dfs(int r, int p)
{
    for(auto i : tree[r])
        if(i != p)
        {
            lvls[i] = 1 + lvls[r];
            dfs(i,r);
        }
}

int main()
{
    int nodes;

    cin >> nodes;

    tree.assign(200001,vector<int>());

    lvls.assign(200001,0);

    int a,b;

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        cin >> a >> b;

        tree[a].push_back(b);

        tree[b].push_back(a);
    }

    for(int x = 1 ; x < nodes + 1; x++)
    {
        cout << "Nodes Connected With " << x << " : ";

        for(int y = 0 ; y < tree[x].size() ; y++)
            cout << tree[x][y] << ' ';
        
        cout << endl;
    }

    dfs(0,0);

    cout << endl;

    int deepest = -1, ind = 0;

    for(int x = 1 ; x < nodes + 1 ; x++)        
        if(lvls[x] > deepest)
        {
            deepest = lvls[x];
            ind = x;
        }

    int diameter = 0;

    lvls.assign(200001,0);

    dfs(ind,0);

    for(int x = 1 ; x < nodes + 1 ; x++)        
        if(lvls[x] >= diameter)
            diameter = lvls[x];

    cout << "Diameter of this Tree is : " << diameter << endl;
}