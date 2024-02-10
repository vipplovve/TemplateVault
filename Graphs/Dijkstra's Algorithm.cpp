#include <bits/stdc++.h>
using namespace std;

int nodes, edges;

vector<vector<pair<int,int>>> graph;

vector<int> distances;

void Dijkstra(int start)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    distances[start] = 0;

    pq.push(make_pair(0,start));

    while(!pq.empty())
    {
        int d = pq.top().first;

        int n = pq.top().second;

        pq.pop();

        for(auto i : graph[n])
        {
            if(i.second + d < distances[i.first])
            {
                distances[i.first] = d + i.second;
                pq.push(make_pair(distances[i.first],i.first));
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

    cout << "The Single Source Shortest Distances For start as " << start << " are :- " << endl << endl;

    Dijkstra(start);
    
    for(int x = 1 ; x < nodes + 1 ; x++)
        cout << x << " : " << distances[x] << endl;
    cout << endl;

    return 0;
}