 #include <bits/stdc++.h>
using namespace std;

int LPS(string f, string s)
{
    int size = f.size();

    vector<vector<int>> dp(size+1,vector<int>(size+1,0));

    for(int x = 0 ; x <= size ; x++)
    {
        dp[x][0] = 0;
        dp[0][x] = 0;
    }

    for(int x = 1 ; x < size + 1 ; x++)
        for(int y = 1 ; y < size + 1 ; y++)
        {
            if(f[x-1] == s[y-1])
                dp[x][y] = 1 + dp[x-1][y-1];
            
            else
                dp[x][y] = max(dp[x-1][y], dp[x][y-1]);
        }

    return dp[size][size];
}

int main()
{
    string str;

    cin>>str;

    string f = str;

    reverse(str.begin(), str.end());

    int op = LPS(f,str);

    cout<<"Minimum Insertions Or Deletions Needed Are : "<<str.size() - op<<endl;

    return 0;
}