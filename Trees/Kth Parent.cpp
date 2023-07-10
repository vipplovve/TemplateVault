#include <bits/stdc++.h>
using namespace std;

int parents[100002];

void DFS(vector<vector<int>> d, int r, int p)
{

    for(auto x : d[r])
    {  
        if(x != p)
        {
            parents[x+1] = r+1;
            DFS(d,x,r);
        }
    }
}


int main()
{
    int nodes;

    cin >> nodes;

    vector<vector<int>> data(nodes, vector<int> ());

    int a[nodes], b[nodes];

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        cin >> a[x] >> b[x];
    }

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        data[a[x]-1].push_back(b[x]-1);
    }

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        data[b[x]-1].push_back(a[x]-1);
    }

    for(int x = 0 ; x < nodes ; x++)
    {
        cout << "Nodes Connected With " << x+1 << " : ";

        for(int y = 0 ; y < data[x].size() ; y++)
            cout << data[x][y] + 1 << ' ';
        
        cout << endl;
    }

    int root;

    cin >> root;

    DFS(data,root-1,-1); 

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