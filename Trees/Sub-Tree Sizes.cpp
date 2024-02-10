#include <bits/stdc++.h>
using namespace std;

int subtrees[100002];

vector<vector<long long>> tree;

void DFS(int r, int p)
{
    subtrees[r] = 1;

    for(auto x : tree[r])
    {   
        if(x != p)
        {
            DFS(x,r);
            subtrees[r] += subtrees[x];
        }
    }
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

    cout << "\nThe Sizes Of Substrees are : -\n\n";

    for(int x = 1 ; x < nodes + 1 ; x++)
        cout << "Sub-Tree Of " << x  << " Has a Size of " << subtrees[x] << '.' << endl; 

    return 0;
}