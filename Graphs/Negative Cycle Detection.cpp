#include <bits/stdc++.h>
using namespace std;

int nodes, edges;

vector<vector<pair<int,int>>> graph;

vector<int> distances;

bool BellmanFord(int start)
{
    distances[start] = 0;

    bool checker = true;

    for(int x = 1 ; x < nodes ; x++)
    {
        for(int y = 1 ; y < nodes + 1 ; y++)
        {
            if(graph[y].empty())
                continue;

            for(auto j : graph[y])
            {
                int b,w;

                b = j.first;
                w = j.second;

                if(distances[y] + w < distances[b])
                    distances[b] = distances[y] + w;
            }

        }
    }

    for(int x = 1 ; x < nodes ; x++)
    {
        for(int y = 1 ; y < nodes + 1 ; y++)
        {
            if(graph[y].empty())
                continue;

            for(auto j : graph[y])
            {
                int b,w;

                b = j.first;
                w = j.second;

                if(distances[y] + w < distances[b])
                {
                    distances[b] = -1e8;
                    checker = false;
                }
            }

        }
    }

    return checker;
}

int main()
{
    cin >> nodes >> edges;

    int a,b,w;

    graph.assign(nodes+1, vector<pair<int,int>> ());

    distances.assign(nodes+1, 1e8);

    for(int x = 0 ; x < edges ; x++)
    {
        cin >> a >> b >> w;

        graph[a].push_back(make_pair(b,w));
    }  

    int start;

    cin >> start;

    bool NoNegativeCycle = BellmanFord(start);

    if(NoNegativeCycle)
        cout << "There are No Negative Cycles in This Graph." << endl;
    else
    {
        cout << "There are One or More Negative Cycles in This Graph." << endl;

        cout << "The Nodes involved in Negative Cycles are :- \n\n";

        for(int x = 1 ; x < nodes + 1 ; x++)
            if(distances[x] == -1e8)
                cout << x << (x == nodes ? "" : " :: ");
        cout << endl;
    }
    
    return 0;
}