#include <bits/stdc++.h>
using namespace std;

int nodes, edges;

vector<vector<pair<int,int>>> graph;

vector<int> MST;

int Prim(int root, int parent, int weight)
{
    int sum = 0;

    MST.assign(nodes + 1, -1);

    vector<bool> visited(nodes+1, false);

    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;

    PQ.push(make_pair(weight,root));

    while(!PQ.empty())
    {
        int currentN = PQ.top().second;

        int currentW = PQ.top().first;

        PQ.pop();

        if(visited[currentN])
            continue;

        visited[currentN] = true;

        sum += currentW;

        for(auto neighbours : graph[currentN])
        {
            int neighboursN = neighbours.first;

            int neighboursW = neighbours.second;

            if(!visited[neighboursN])
            {
                PQ.push(make_pair(neighboursW,neighboursN));

                MST[neighboursN] = currentN;
            }
        }
    }

    return sum;
}

int main()
{
    cin >> nodes >> edges;

    graph.assign(nodes + 1, vector<pair<int,int>> ());

    for(int x = 0 ; x < edges ; x++)
    {
        int a,b,w;

        cin >> a >> b >> w;

        graph[a].push_back(make_pair(b,w));

        graph[b].push_back(make_pair(a,w));
    }

    cout << "The MST Consists of These Edges :- \n\n";

    int answer = Prim(1,-1,0);

    for(int x = 2 ; x < nodes + 1 ; x++)
        cout << MST[x] <<" : " << x << endl;

    cout << endl;
    
    cout << "Total Weight of the Minimum Spanning Tree : " << answer << endl;

    return 0;
}