#include <bits/stdc++.h>
using namespace std;

bool safeplace(vector<vector<int>>maze,vector<vector<int>>visited,int n,int x,int y)
{
    if((x>=0 && x<=n-1) && (y>=0 && y<=n-1) && visited[x][y]==0 && maze[x][y]==1)
    return true;
    else
    return false;
}
void ratinamaze(vector<vector<int>>maze,vector<string>&ans,vector<vector<int>>visited,int x,int y,int n, string path)
{
    if(x==n-1 && y==n-1) // base case.
    {
        ans.push_back(path);
        return;
    }

    visited[x][y]=1;
    int x2,y2;

    //D
    x2=x+1;
    y2=y;
    if(safeplace(maze,visited,n,x2,y2))
    {
        path.push_back('D');
        ratinamaze(maze,ans,visited,x2,y2,n,path);
        path.pop_back();
    }

    //U
    x2=x-1;
    y2=y;
    if(safeplace(maze,visited,n,x2,y2))
    {
        path.push_back('U');
        ratinamaze(maze,ans,visited,x2,y2,n,path);
        path.pop_back();
    }

    //L
    x2=x;
    y2=y-1;
    if(safeplace(maze,visited,n,x2,y2))
    {
        path.push_back('L');
        ratinamaze(maze,ans,visited,x2,y2,n,path);
        path.pop_back();
    }

    //R
    x2=x;
    y2=y+1;
    if(safeplace(maze,visited,n,x2,y2))
    {
        path.push_back('R');
        ratinamaze(maze,ans,visited,x2,y2,n,path);
        path.pop_back();
    }

    visited[x][y]=0;
    
}
int main() 
{
    vector<string> ans;
    vector<vector<int>>maze;
    string path;

    int n;
    n=4; //enter value of maze-order here.

    maze={
        {1,0,0,0},
        {1,1,0,0},
        {1,1,0,0},
        {1,1,1,1}
    }; //enter the maze here.

    vector<vector<int>>visited=maze;
    for(int x=0;x<4;x++)
    for(int y=0;y<4;y++)
    visited[x][y]=0;

    ratinamaze(maze,ans,visited,0,0,n,path);
    sort(ans.begin(),ans.end());

    cout<<"No. of possible Ways: "<<ans.size()<<endl;
    for(int x=0;x<n;x++)
    cout<<"Method #"<<x+1<<": "<<ans[x]<<endl;
    return 0;
}