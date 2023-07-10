#include <bits/stdc++.h>
using namespace std;

long long parent[100002][21];

void DFS(vector<vector<int>> t , int r, int p)
{
    for(auto x : t[r])
        if(x != p)
        {
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

    int root;

    cin >> root;

    DFS(tree,root-1,0);

    BinLift(nodes);

    int n,k;

    cin >> n >> k;

    cout << endl << k << "th Parent of " << n << " is : " << KthParent(n-1,k) + 1 << endl;

    return 0;
}