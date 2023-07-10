#include <bits/stdc++.h>
using namespace std;

int subtrees[100002];

void DFS(vector<vector<int>> d, int r, int p)
{
    subtrees[r] = 1;

    for(auto x : d[r])
    {   
        if(x != p)
        {
            DFS(d,x,r);
            subtrees[r] += subtrees[x];
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

    cout << "\nThe Sizes Of Substrees are : -\n\n";

    for(int x = 0 ; x < nodes ; x++)
        cout << "Sub-Tree Of " << x + 1 << " Has a Size of " << subtrees[x] << '.' << endl; 

    return 0;
}