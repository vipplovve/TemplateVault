/*
    || साम्ब-सदाशिव ||

    author: viplove tyagi (@vipplovve).

    This generator script is designed for competitive programming stress testing.
    It uses mt19937 for random number generation.
*/

#include <bits/stdc++.h>

using namespace std;

using str = string;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const ll INF = 4e18;
const ld EPS = 1e-10;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Precise cout << fixed << setprecision(15);
#define endl '\n'

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randomInt(int low, int high) 
{
    uniform_int_distribution<int> dist(low, high);
    return dist(rng);
}

ll randomLong(ll low, ll high) 
{
    uniform_int_distribution<ll> dist(low, high);
    return dist(rng);
}

double randomDouble(double low, double high) 
{
    uniform_real_distribution<double> dist(low, high);
    return dist(rng);
}

string randomString(int length) 
{
    string chars = "abcdefghijklmnopqrstuvwxyz";
    string result;

    for (int i = 0; i < length; ++i) 
        result += chars[randomInt(0, 25)];

    return result;
}

const ll Nmin = 1;
const ll Nmax = 2e5;
const ll Vmin = 1;
const ll Vmax = 1e9;   

int main() 
{
    FastIO
    
    ll t = 1;

    cout << t << endl;

    for (int test = 1; test <= t; ++test) 
    {
        // Write Test-Cases Here..
    }

    return 0;
}
