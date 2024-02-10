#include <bits/stdc++.h>
using namespace std;

priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> PQ;

vector<pair<int,int>> MST;

class DisjointSet
{
    vector<int> size, rank, parent;

public:

    DisjointSet(int n)
    {
        size.assign(n+1, 1);

        rank.assign(n+1, 0);

        parent.assign(n+1, 0);

        for(int x = 0 ; x < n + 1 ; x++)
            parent[x] = x;
    }

    int UltimateParent(int a)
    {
        if(parent[a] == a)
            return a;

        else
            return parent[a] = UltimateParent(parent[a]);
    }

    void UnionByRank(int a, int b)
    {
        int ParentA = UltimateParent(a);

        int ParentB = UltimateParent(b);

        if(ParentA == ParentB)
            return;

        else if(rank[ParentA] > rank[ParentB])
            parent[ParentB] = ParentA;

        else if(rank[ParentA] < rank[ParentB])
            parent[ParentA] = ParentB;

        else
            parent[ParentA] = ParentB;            
    }

    void UnionBySize(int a, int b)
    {
        int ParentA = UltimateParent(a);

        int ParentB = UltimateParent(b);

        if(ParentA == ParentB)
            return;

        else if(size[ParentA] > size[ParentB])
        {
            parent[ParentB] = ParentA;

            size[ParentB] += size[ParentA];
        }

        else if(size[ParentA] < size[ParentB])
        {
            parent[ParentA] = ParentB;
            
            size[ParentA] += size[ParentB];
        }

        else
        {
            parent[ParentA] = ParentB;
            
            size[ParentA] += size[ParentB];
        }
    }
};

int Kruskal(DisjointSet DS)
{
    int MSTweight = 0;

    while(!PQ.empty())
    {
        auto triplet = PQ.top();

        PQ.pop();

        int weight, a, b;

        weight = triplet.first;

        a = triplet.second.first;

        b = triplet.second.second;

        if(DS.UltimateParent(a) != DS.UltimateParent(b))
        {
            MSTweight += weight;

            DS.UnionBySize(a,b);

            MST.push_back(make_pair(a,b));
        }
    }

    return MSTweight;
}

int main()
{
    int nodes, edges;

    cin >> nodes >> edges;

    DisjointSet DS(nodes);

    while(edges--)
    {
        int a,b,w;

        cin >> a >> b >> w;

        PQ.push(make_pair(w,make_pair(a,b)));
    }

    int MSTW = Kruskal(DS);

    cout << "Weight of The Min. Spanning Tree is : " << MSTW << endl;
    
    cout << endl;

    cout << "The Minimum Spanning Tree is :- \n\n";

    for(auto i : MST)
        cout << i.first << " : " << i.second << endl;

    return 0;
}