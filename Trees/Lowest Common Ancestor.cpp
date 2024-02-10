#include <bits/stdc++.h>
using namespace std;

long long parent[100002][21];

long long levels[100002];

vector<vector<long long>> tree;

void DFS(int r, int p)
{
    for(auto x : tree[r])
        if(x != p)
        {
            levels[x] = levels[r] + 1;
            parent[x][0] = r;
            DFS(x,r);
        }   
}

void BinLift(int n)
{
    int limit = ceil(log2(n));

    for(int x = 1 ; x < limit ; x++)
    {
        for(int y = 1 ; y < n + 1 ; y++)
        {
            int curr = parent[y][x-1];

            parent[y][x] = parent[curr][x-1];
        }
    }
}

long long LCA(int node1, int node2, int n)
{
    if(levels[node1] < levels[node2])
        swap(node1,node2);

    for(int curr = ceil(log2(n)) ; curr >= 0 ; curr--)
        if(levels[node1] - pow(2,curr) >= levels[node2])
            node1 = parent[node1][curr];

    if(node1 == node2)
        return node1;

    for(int curr = ceil(log2(n)) ; curr >= 0 ; curr--)
    {
        if(parent[node1][curr] != parent[node2][curr])
        {
            node1 = parent[node1][curr];
            node2 = parent[node2][curr];
        }
    }

    return parent[node1][0];
}

int main()
{
    int nodes;

    cin >> nodes;

    tree.assign(200001,vector<long long>());

    int a,b;

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        cin >> a >> b;

        tree[a].push_back(b);

        tree[b].push_back(a);
    }

    for(int x = 1 ; x < nodes + 1 ; x++)
    {
        cout << "Nodes Connected With " << x << " : ";

        for(int y = 0 ; y < tree[x].size() ; y++)
            cout << tree[x][y] << ' ';
        
        cout << endl;
    }

    DFS(1,0);

    BinLift(nodes);

    int v1,v2;

    cin >> v1 >> v2;

    cout << endl << "Lowest Common Ancestor Of " << v1 << " & " << v2 << " is : ";

    cout << LCA(v1,v2,nodes) + 1 << endl;
    
    return 0;
}