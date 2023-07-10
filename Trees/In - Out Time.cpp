#include <bits/stdc++.h>
using namespace std;

int in[100000], out[100000];
int t;

void DFS(vector<vector<int>> d, int r, int v)
{
    t++;

    in[r] = t;

    for(auto x : d[r])
    {   
        if(x != v)
            DFS(d,x,r);
    }
    t++;

    out[r] = t;
}

int main()
{
    int nodes;

    cin >> nodes;

    vector<vector<int>> tree(nodes, vector<int> ());

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

    DFS(tree,root-1,-1);

    cout << endl;

    cout << "\nThe In-Out Time of Each Node is : -\n\n";

    for(int x = 0 ; x < nodes ; x++)
        cout << x + 1 << " : " << in[x] << " - " << out[x] << endl;   

    return 0;
}