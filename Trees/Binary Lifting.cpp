#include <bits/stdc++.h>
using namespace std;

long long parent[200001][21];

vector<vector<long long>> tree;
void DFS(int r, int p)
{
    for(auto x : tree[r])
        if(x != p)
        {
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

int KthParent(int n, int k)
{
    if(!k)
        return n;

    else
    {
        int p = log2(k);

        int val = pow(2,p);

        return KthParent(parent[n][p], k - val);
    }
}

int main()
{
    int nodes;

    cin >> nodes;

    tree.assign(200001,vector <long long>());

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

    int root;

    cin >> root;

    DFS(root,0);

    BinLift(nodes);

    int n,k;

    cin >> n >> k;

    cout << endl << k << "th Parent of " << n << " is : " << KthParent(n-1,k) + 1 << endl;

    return 0;
}