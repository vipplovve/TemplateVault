#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define setbits(x) __builtin_popcount(x)

vector<ll> SegmentTree;

void build(vector<ll> &data, ll input)
{
    SegmentTree.assign(2*input, 0);

    for(ll x = 0 ; x < input ; x++)
        SegmentTree[x + input] = data[x];

    for(ll x = input - 1 ; x > 0 ; x--)
        SegmentTree[x] = __gcd(SegmentTree[2*x + 1], SegmentTree[2*x]);
}

ll answerQuery(ll current, ll low, ll high, ll lowest, ll highest)
{
    if(lowest <= low && highest >= high)
        return SegmentTree[current];

    if(low > highest || high < lowest)
        return 0;

    ll middle = low + ((high - low) >> 1);

    ll ans = 0;

    ans = __gcd(ans, answerQuery(2*current, low, middle, lowest, highest));
    ans = __gcd(ans, answerQuery(2*current + 1, middle + 1, high, lowest, highest));

    return ans;
}

void update(ll index, ll value, ll sz)
{
    SegmentTree[sz + index] = value;

    for(ll x = (sz + index) / 2 ; x > 0 ; x /= 2)
        SegmentTree[x] = __gcd(SegmentTree[2*x], SegmentTree[2*x + 1]);
}

void updateR(ll current, ll low, ll high, ll lowest, ll highest, ll value)
{
    if(lowest <= low && highest >= high)
    {
        SegmentTree[current] = value;
        return;
    }
 
    if(low > highest || high < lowest)
        return;
 
    ll middle = low + ((high - low) >> 1);
 
    updateR(2*current, low, middle, lowest, highest, value);
    updateR(2*current + 1, middle + 1, high, lowest, highest,value);

    SegmentTree[current] = __gcd(SegmentTree[2*current], SegmentTree[2*current + 1]);
}

int main()
{
    ll input;

    cin >> input;

    ll queries;

    cin >> queries;

    vector<ll> data(input);

    for(ll x = 0 ; x < input ; x++)
        cin >> data[x];

    while(setbits(input) != 1)
    {
        input++;
        data.push_back(0);
    }
    
    build(data, input);

    while(queries--)
    {
        ll t, l, r;

        cin >> t >> l >> r;

        if(t == 2)
            cout << answerQuery(1, 1, input, l, r) << endl;
        else
            updateR(1,1,input,l,l,r);
    }

    // for(long x = 0 ; x < SegmentTree.size() ; x++)
    //     cout << x << " : " << SegmentTree[x] << endl;

    return 0;
}
