#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph, solution;

bool FloydWarshall(int s)
{
    for(int x = 1 ; x <= s ; x++)
        for(int y = 1 ; y <= s ; y++)
            for(int z = 1 ; z <= s ; z++)
                solution[y][z] = min(solution[y][z], solution[y][x] + solution[x][z]);

    for(int a = 1 ; a <= s ; a++)
        if(solution[a][a] < 0)
            return true;

    return false;
}

int main()
{
    int size;

    cin >> size;

    graph.assign(size + 1, vector<int> (size + 1));
    
    solution.assign(size + 1, vector<int> (size + 1));

    for(int x = 1 ; x <= size ; x++)
        for(int y = 1 ; y <= size ; y++)
        {
            cin >> graph[x][y];

            solution[x][y] = graph[x][y];

            if(x == y)
                solution[x][y] = 0;

            if(graph[x][y] == 1000000)
                solution[x][y] = 1e8;
        }

    bool NegativeCycle = FloydWarshall(size);

    cout << "Shortest Paths Between Every Node :- \n\n";

    for(int x = 1 ; x <= size ; x++)
    {
        for(int y = 1 ; y <= size ; y++)
        {
            cout << "From " << x << " To " << y << " : ";
            if(solution[x][y] == 1e8)
                cout << "Unreachable." << endl;
            else if(solution[x][y] == 0)
                cout << "Already There." << endl;
            else
                cout << solution[x][y] << endl;
        }
        cout << endl;
    }

    if(NegativeCycle)
        cout << "Negative Cycle Exists." << endl;
    else
        cout << "Negative Cycle don't Exist." << endl;
    return 0;
}