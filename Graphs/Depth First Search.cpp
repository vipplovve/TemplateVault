/*
    || धर्मं चर। धर्मान्न प्रमदितव्यम् ||
*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

using ll = long long;
using ld = long double;
const ld Pi = 3.141592653589793238462643;
const ld e = 2.718281828459045235360;
const ll MOD = 100;

#define f(variable,s,e,j) for(ll variable = s ; variable < e ; variable+=j)
#define fr(variable,s,e,j) for(ll variable = s ; variable > e ; variable-=j)
#define test(n) while(n--)
#define trav(x,y) for(auto x : y)
#define endl '\n'

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mems(x,y) memset(x , y, sizeof(x));
#define pb(v) push_back(v);
#define pp pop_back();

#define MODadd(x,y) ((x % MOD) + (y % MOD) + MOD ) % MOD
#define MODsub(x,y) ((max(x,y) % MOD) - (min(x,y) % MOD) + MOD ) % MOD
#define MODmul(x,y) ((x % MOD) * (y % MOD)) % MOD

#ifndef vipplovve
#define debug(value) cerr << #value << " : " << value << endl;
#else
#define debug(value);
#endif

vector<vector<int>> graph;

vector<bool> vis;

void dfs(int root)
{
    cout << root << ' ';

    vis[root] = true;

    for(auto son : graph[root])
        if(!vis[son])
            dfs(son);
}

int main()
{
    #ifndef vipplovve
        freopen("errors.txt","w",stderr);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto beg = high_resolution_clock::now();

    //Code Here.

    int nodes, edges;

    cin >> nodes >> edges;

    graph.assign(200001,vector<int>());

    vis.assign(200001,false);

    int a,b;

    for(int x = 0 ; x < edges ; x++)
    {
        cin >> a >> b;

        graph[a].push_back(b);

        graph[b].push_back(a);
    }

    for(int x = 1 ; x < nodes + 1 ; x++)
    {
        cout << "Nodes Connected With " << x << " Are : ";

        for(auto i : graph[x])
            cout << i << ' ';
        cout << endl;
    }

    int root;

    cin >> root;

    cout << endl << "Depth-First Search Traversal of this Graph With Root as " << root << " :- " << endl << endl;

    dfs(root);

    auto end = high_resolution_clock::now();

    auto duration = duration_cast <microseconds> (end - beg);
    
    #ifndef vipplovve
        cerr << endl << "Time Taken : " << duration.count() / 1000 << " ms." << endl;
    #endif

    return 0;
}
