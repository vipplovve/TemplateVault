#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

vector<bool> vis, exists;

vector<int> topS;

void TopSort(int);

void dfs(int root)
{
    vis[root] = true;

    for(auto i : graph[root])
        if(!vis[i])
            dfs(i);

    topS.push_back(root);
}

void TopSort(int nodes)
{
    for(int x = 1 ; x < 200001 ; x++)
        if(!vis[x] && exists[x])
            dfs(x);
}

int main()
{

    int nodes, edges;

    cin >> nodes >> edges;
    
    graph.assign(200001,vector<int>());

    vis.assign(200001,false);

    exists.assign(200001,false);

    int a,b;

    for(int x = 0 ; x < edges ; x++)
    {
        cin >> a >> b;

        exists[a] = true;
        exists[b] = true;

        graph[a].push_back(b);
    }

    for(int x = 1 ; x < 200001 ; x++)
    {
        if(exists[x])
        {
            cout << "Nodes Connected With " << x << " : ";

            for(auto i : graph[x])
                cout << i << ' ';
            cout << endl;
        }
    }

    TopSort(nodes);

    reverse(topS.begin(), topS.end());

    cout << endl << "The Topological Sort of This Graph is : " << endl << endl;

    for(auto i : topS)
        cout << i << ' ';
    cout << endl;

    return 0;
}