#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int nodes, edges;

    cin >> nodes >> edges;

    DisjointSet DS(nodes);

    while(edges--)
    {
        int a,b;

        cin >> a >> b;

        DS.UnionBySize(a,b);

        int c,d;

        cout << "Enter Query Pair : ";

        cin >> c >> d;

        if(DS.UltimateParent(c) == DS.UltimateParent(d))
            cout << "Yes They Belong in the Same Component." << endl;

        else
            cout << "No They Don't Belong in the Same Component." << endl;
    }

    return 0;
}