#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

vector<bool> vis;

void dfs(int root)
{
    cout << root << ' ';

    vis[root] = true;

    for(auto son : graph[root])
        if(!vis[son])
            dfs(son);
}

int main()
{
    int nodes, edges;

    cin >> nodes >> edges;

    graph.assign(200001,vector<int>());

    vis.assign(200001,false);

    int a,b;

    for(int x = 0 ; x < edges ; x++)
    {
        cin >> a >> b;

        graph[a].push_back(b);

        graph[b].push_back(a);
    }

    for(int x = 1 ; x < nodes + 1 ; x++)
    {
        cout << "Nodes Connected With " << x << " Are : ";

        for(auto i : graph[x])
            cout << i << ' ';
        cout << endl;
    }

    int root;

    cin >> root;

    cout << endl << "Depth-First Search Traversal of this Graph With Root as " << root << " :- " << endl << endl;

    dfs(root);
    
    return 0;
}
