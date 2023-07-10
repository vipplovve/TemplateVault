#include <bits/stdc++.h>
using namespace std;

long long parent[100002][21];

long long levels[100002];

void DFS(vector<vector<int>> t , int r, int p)
{
    for(auto x : t[r])
        if(x != p)
        {
            levels[x] = levels[r] + 1;
            parent[x][0] = r;
            DFS(t,x,r);
        }   
}

void BinLift(int n)
{
    int limit = ceil(log2(n));

    for(int x = 1 ; x < limit ; x++)
    {
        for(int y = 0 ; y < n ; y++)
        {
            int curr = parent[y][x-1];

            parent[y][x] = parent[curr][x-1];
        }
    }
}

long long LCA(int node1, int node2, int n)
{
    node1--;
    node2--;

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

    vector<vector<int>> tree(nodes, vector<int>());

    int a,b;

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        cin >> a >> b;

        tree[a-1].push_back(b-1);

        tree[b-1].push_back(a-1);
    }

    for(int x = 0 ; x < nodes ; x++)
    {
        cout << "Nodes Connected With " << x+1 << " : ";

        for(int y = 0 ; y < tree[x].size() ; y++)
            cout << tree[x][y] + 1 << ' ';
        
        cout << endl;
    }

    DFS(tree,0,0);

    BinLift(nodes);

    int v1,v2;

    cin >> v1 >> v2;

    cout << endl << "Lowest Common Ancestor Of " << v1 << " & " << v2 << " is : ";

    cout << LCA(v1,v2,nodes) + 1 << endl;
    
    return 0;
}