#include <bits/stdc++.h>
using namespace std;

int nodes, edges;

vector<vector<pair<int,int>>> graph;

vector<int> distances;

void BellmanFord(int start)
{
    distances[start] = 0;

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

    cout << "Graph Traversal :- \n\n";

    for(int x = 1 ; x < nodes + 1 ; x++)
    {
        cout << x << " : ";

        for(auto i : graph[x])
            cout << i.first << " - " << i.second << ". ";
        cout << endl;
    }  

    cout << endl;    

    int start;

    cin >> start;

    cout << "The Single Source Shortest Distances (Starting Node As " << start << ") are :- " << endl << endl;

    BellmanFord(start);
    
    for(int x = 1 ; x < nodes + 1 ; x++)
        cout << x << " : " << distances[x] << endl;
    cout << endl;
    
    return 0;
}