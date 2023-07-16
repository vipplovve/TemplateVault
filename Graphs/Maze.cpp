#include <bits/stdc++.h>
using namespace std;

int Cmove[] = {-1,0,0,1,1,1,-1,-1};
int Rmove[] = {0,1,-1,0,1,-1,-1,1};

int row, col;

queue<int> R,C;

vector<vector<bool>> vis;

int moves, nxt, current;

int solve(vector<vector<int>> m)
{
    R.push(0);
    C.push(0);

    bool found = false;

    current = 1;

    vis[0][0] = true;

    while(!R.empty() && !C.empty())
    {
        int Cr = R.front();
        int Cc = C.front();

        R.pop();
        C.pop();

        if(m[Cr][Cc] == 3)
        {
            found = true;
            break;
        }

        for(int x = 0 ; x < 8 ; x++)
        {
            int newr = Cr + Rmove[x];
            int newc = Cc + Cmove[x];

            if(newr < 0 || newr >= row || newc < 0 || newc >= col)
                continue;

            if(vis[newr][newc])
                continue;

            if(!m[newr][newc])
                continue;

            R.push(newr);
            C.push(newc);

            vis[newr][newc] = true;
            nxt++;
        }

        current--;

        if(!current)
        {
            current = nxt;
            nxt = 0;
            moves++;
        }
    }

    if(found)
        return moves;

    return -1;
}

int main()
{
    cin >> row >> col;

    vector<vector<int>> maze (row, vector<int> (col));

    vis.assign(row, vector<bool> (col,false));

    for(int x = 0 ; x < row ; x++)
        for(int y = 0 ; y < col ; y++)
            cin >> maze[x][y];

    long long answer = solve(maze);

    cout << "It would take " << answer << " Moves to solve The Maze." << endl;

    return 0;
}   