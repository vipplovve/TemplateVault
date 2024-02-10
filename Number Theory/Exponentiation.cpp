#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll BinExponentiate(ll a, ll b)
{
    ll ans = 1;

    while(b)
    {
        if(b & 1)
            ans *= a;
        b /= 2;
        a *= a;
    }

    return ans;
}

ll BinaryExp(ll a, ll b)
{
    if(!b)
        return 1;

    if(b & 1)
        return a*BinaryExp(a, b - 1);
    else
        return BinaryExp(a*a, b/2);
}

int main()
{
    ll a, b;

    cin >> a >> b;

    ll ans = BinExponentiate(a, b);

    ll sna = BinaryExp(b, a);

    cout << ans << " : " << sna << endl;

    return 0;
}
