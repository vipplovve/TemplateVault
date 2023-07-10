#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> d, int r, int v)
{
    cout << r + 1 << ' ';

    for(auto x : d[r])
    {   
        if(x != v)
            DFS(d,x,r);
    }
}

int main()
{
    int nodes;

    cin >> nodes;

    vector<vector<int>> data(nodes, vector<int> ());

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        int a,b;

        cin >> a >> b;

        data[a-1].push_back(b-1);

        data[b-1].push_back(a-1);
    }

    for(int x = 0 ; x < nodes ; x++)
    {
        cout << "Nodes Connected With " << x+1 << " : ";

        for(int y = 0 ; y < data[x].size() ; y++)
            cout << data[x][y] + 1 << ' ';
        
        cout << endl;
    }

    int value;

    cin >> value;

    int root;

    cin >> root;

    cout << "\nThe DFS Traversal is : \n\n";

    DFS(data,root-1,value);

    return 0;
}