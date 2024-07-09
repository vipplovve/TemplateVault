#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;

int nodes, edges;

vector<bool> vis, exists;

vector<int> topS;

void TopSort(int);

vector<int> SSSP;

void dfs(int root)
{
    vis[root] = true;

    for(auto i : graph[root])
        if(!vis[i.first])
            dfs(i.first);

    topS.push_back(root);
}

void TopSort(int nodes)
{
    for(int x = 1 ; x < 200001 ; x++)
        if(!vis[x] && exists[x])
            dfs(x);
}

void SSSPath(int start)
{
    SSSP[start] = 0;

    for(int x = 0 ; x < nodes ; x++)
    {
        int current = topS[x];

        if(SSSP[current] != 1e8)
        {
            for(auto p : graph[current])
            {
                int n = p.first;
                int e = p.second;

                if(SSSP[n] != 1e8)
                    SSSP[n] = min(SSSP[n],SSSP[current] + e);

                else
                    SSSP[n] = SSSP[current] + e;
            }
        }
    }

}

int main()
{
    cin >> nodes >> edges;
    
    graph.assign(200001,vector<pair<int,int>>());

    vis.assign(200001,false);

    exists.assign(200001,false);

    SSSP.assign(200001,1e8);

    int a,b,w;

    for(int x = 0 ; x < edges ; x++)
    {
        cin >> a >> b >> w;

        exists[a] = true;
        exists[b] = true;

        graph[a].push_back(make_pair(b,w));
    }

    for(int x = 1 ; x < 200001 ; x++)
    {
        if(exists[x])
        {
            cout << "Nodes Connected With " << x << " : ";

            for(auto i : graph[x])
                cout << "( " << i.first << ", " << i.second << " )";
            cout << endl;
        }
    }

    cout << endl << "The Topological Sort of This Graph is : " << endl << endl;

    TopSort(nodes);

    reverse(topS.begin(), topS.end());

    for(auto i : topS)
        cout << i << ' ';
    cout << endl << endl;

    int start;

    cin >> start;
    
    SSSPath(start);

    cout << "Single Source Shortest Paths For Start Node As " << start << " are :-" << endl << endl;

    for(int x = 1 ; x < 200002 ; x++)
        if(exists[x])
            cout << x << " : " << SSSP[x] << endl;

    return 0;
}