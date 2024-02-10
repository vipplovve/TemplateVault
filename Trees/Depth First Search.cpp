#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> tree;

vector<long long> traversal;

void DFS(int root, int parent)
{
    traversal.push_back(root);

    for(auto i : tree[root])
        if(i != parent)
            DFS(i,root);
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

    cout << endl << "The DFS Traversal is : -\n\n";

    for(auto value : traversal)
        cout << value << " ";
    cout << endl;
    
    return 0;
}