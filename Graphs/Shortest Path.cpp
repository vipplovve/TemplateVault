#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

vector<bool> vis;

vector<int> lvl, predecessor;

void bfs(int root)
{
    queue <int> q;

    q.push(root);

    vis[root] = true;

    while(!q.empty())
    {
        int current = q.front();

        q.pop();

        vis[current] = true;

        for(auto neighbour : graph[current])
            if(!vis[neighbour])
            {
                lvl[neighbour] = 1 + lvl[current];

                q.push(neighbour);

                predecessor[neighbour] = current;
                
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

    lvl.assign(200001,0);

    predecessor.assign(200001,0);

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

    int start, end;

    cin >> start >> end;

    bfs(start);

    cout << endl << "Shortest Distance Between " << start << " & " << end << " is : " << lvl[end] << endl;

    vector <int> path;

    path.push_back(end);

    while(predecessor[end])
    {
        path.push_back(predecessor[end]);
        end = predecessor[end];
    }

    cout << endl << "The Path is : ";

    reverse(path.begin(), path.end());

    for(auto i : path)
        cout << i << ' ';
    cout << endl;

    return 0;
}
