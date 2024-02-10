#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

vector<bool> vis;

void bfs(int root)
{
    queue <int> q;

    q.push(root);

    vis[root] = true;

    while(!q.empty())
    {
        int current = q.front();

        cout << current << ' ';

        q.pop();

        vis[current] = true;

        for(auto neighbour : graph[current])
            if(!vis[neighbour])
            {
                q.push(neighbour);
                vis[neighbour] = true;
            }
    }

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

    cout << endl << "The Breadth First Search Traversal with Root as " << root << " is : " << endl << endl;

    bfs(root);

    return 0;
}
