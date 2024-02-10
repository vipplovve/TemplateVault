#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

vector<bool> vis;

vector<int> in, out;

int t;

void dfs(int root)
{
    vis[root] = true;

    in[root] = ++t;

    for(auto son : graph[root])
        if(!vis[son])
            dfs(son);

    out[root] = ++t;
}

int main()
{
    int nodes, edges;

    cin >> nodes >> edges;

    graph.assign(200001,vector<int>());

    vis.assign(200001,false);

    in.assign(200001,0);

    out.assign(200001,0);

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

    dfs(root);

    cout << endl << "Node : " << "{ In Time, Out Time }." << endl << endl;

    for(int x = 1 ; x <= nodes ; x++)
        cout << "  " << x << " : " << " { " << in[x] << ", " << out[x] << " }." << endl << endl;

    return 0;
}
