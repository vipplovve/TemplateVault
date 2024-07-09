#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define setbits(x) __builtin_popcount(x)

vector<ll> SegmentTree;

vector<ll> Lazy;

void build(vector<ll> &data, ll input)
{
    SegmentTree.assign(2*input, 1e12);

    Lazy.assign(2*input, 0);

    for(ll x = 0 ; x < input ; x++)
        SegmentTree[x + input] = data[x];

    for(ll x = input - 1 ; x > 0 ; x--)
        SegmentTree[x] = SegmentTree[2*x + 1] + SegmentTree[2*x];
}

ll answerQuery(ll current, ll low, ll high, ll lowest, ll highest)
{
    if(Lazy[current] != 0)
    {
        SegmentTree[current] += Lazy[current];

        if(high != low)
        {
            Lazy[2*current] += Lazy[current];
            Lazy[2*current + 1] += Lazy[current];
        }

        Lazy[current] = 0;
    }

    if(lowest <= low && highest >= high)
        return SegmentTree[current];

    if(low > highest || high < lowest)
        return 0;

    ll middle = low + ((high - low) >> 1);

    ll ans = 0;

    ans += answerQuery(2*current, low, middle, lowest, highest);
    ans += answerQuery(2*current + 1, middle + 1, high, lowest, highest);

    return ans;
}

void lazyUpdate(ll current, ll low, ll high, ll lowest, ll highest, ll value)
{
    if(Lazy[current] != 0)
    {
        SegmentTree[current] += Lazy[current];

        if(low != high)
        {
            Lazy[2*current] += Lazy[current];
            Lazy[2*current + 1] += Lazy[current];
        }

        Lazy[current] = 0;
    }

    if(low > highest || high < lowest)
        return;

    if(lowest <= low && highest >= high)
    {
        SegmentTree[current] += value;

        if(high != low)
        {
            Lazy[2*current] += value;
            Lazy[2*current + 1] += value;
        }

        return;
    }
 
    ll middle = low + ((high - low) >> 1);
 
    lazyUpdate(2*current, low, middle, lowest, highest, value);
    lazyUpdate(2*current + 1, middle + 1, high, lowest, highest,value);

    SegmentTree[current] = SegmentTree[2*current] + SegmentTree[2*current + 1];
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
        ll t;

        cin >> t;

        if(t == 2)
        {
            ll l,r;

            cin >> l >> r;

            cout << answerQuery(1,1,input,l,r) << endl;
        }

        else
        {
            ll l, r, v;

            cin >> l >> r >> v;

            lazyUpdate(1,1,input,l,r,v);
        }
    }

    return 0;
}
