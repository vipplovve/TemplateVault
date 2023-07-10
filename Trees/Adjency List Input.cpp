#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes;

    cin >> nodes;

    vector<vector<int>> data(nodes, vector<int> ());

    for(int x = 0 ; x < nodes - 1 ; x++)
    {
        int a,b;

        cin >> a >> b;

        data[a-1].push_back(b);

        data[b-1].push_back(a);
    }

    for(int x = 0 ; x < nodes ; x++)
    {
        cout << "Nodes Connected With " << x+1 << " : ";

        for(int y = 0 ; y < data[x].size() ; y++)
            cout << data[x][y] << ' ';
        
        cout << endl;
    }
    
    return 0;
}