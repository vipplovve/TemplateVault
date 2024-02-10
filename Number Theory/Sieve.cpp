#include <bits/stdc++.h>
using namespace std;

vector<long long> Sieve(long long n)
{
    bool primes[n+1];

    memset(primes, true, sizeof(primes));

    for(int x = 2 ; x*x <= n ; x++)
        if(primes[x])
            for(int i = x*x ; i <= n ; i += x)
                primes[i] = false;

    vector<long long> ans;

    for(long long x = 2 ; x <= n ; x++)
        if(primes[x])
            ans.push_back(x);

    return ans;
}

int main()
{
    vector<long long> sol = Sieve(20147);

    for(auto i : sol)
        cout << i << ' ';
    cout << endl;

    return 0;
}