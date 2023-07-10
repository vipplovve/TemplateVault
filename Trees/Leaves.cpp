#include <bits/stdc++.h>
using namespace std;

long long leaves[100002];

void DFS(vector<vector<int>> t , int r, int p)
{   
    if(t[r].size() == 1)
        leaves[r] = 1;

    for(auto x : t[r])
        if(x != p)
        {
            DFS(t,x,r);

            leaves[r] += leaves[x];
        }
}

int main()
{
    int nodes;

    cin >> nodes;

    vector<vector<int>> tree(nodes, vector<int>());

    int a,b;

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        cin >> a >> b;

        tree[a-1].push_back(b-1);

        tree[b-1].push_back(a-1);
    }

    for(int x = 0 ; x < nodes ; x++)
    {
        cout << "Nodes Connected With " << x+1 << " : ";

        for(int y = 0 ; y < tree[x].size() ; y++)
            cout << tree[x][y] + 1 << ' ';
        
        cout << endl;
    }

    int root;

    cin >> root;

    DFS(tree,root-1,0);

    cout << "\nTotal Number of Leaves are : " << leaves[root - 1] << endl;

    return 0;
}