#include <bits/stdc++.h>
using namespace std;

int parents[200001];

vector<vector<long long>> tree;

void DFS(int r, int p)
{

    for(auto x : tree[r])
    {  
        if(x != p)
        {
            parents[x] = r;
            DFS(x,r);
        }
    }
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

    int root;

    cin >> root;

    DFS(root,0); 

    int child, k;

    cin >> child >> k;

    cout << endl << k << "th Parent of " << child << " is : " ;
    
    while(k-- && child != 1)
    {
        child = parents[child];
    }

    cout << child << endl;

    return 0;
}