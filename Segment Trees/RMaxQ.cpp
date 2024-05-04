#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define setbits(x) __builtin_popcount(x)
#define vec vector

vec<ll> SegmentTreeMax;

void buildMax(vector<ll> &data, ll input)
{
    SegmentTreeMax.assign(2*input, -1e12);

    for(ll x = 0 ; x < input ; x++)
        SegmentTreeMax[x + input] = data[x];

    for(ll x = input - 1 ; x > 0 ; x--)
        SegmentTreeMax[x] = max(SegmentTreeMax[2*x + 1], SegmentTreeMax[2*x]);
}

ll answerMax(ll current, ll low, ll high, ll lowest, ll highest)
{
    if(lowest <= low && highest >= high)
        return SegmentTreeMax[current];

    if(low > highest || high < lowest)
        return -1e12;

    ll middle = low + ((high - low) >> 1);

    ll ans = -1e12;

    ans = max(ans, answerMax(2*current, low, middle, lowest, highest));
    ans = max(ans, answerMax(2*current + 1, middle + 1, high, lowest, highest));

    return ans;
}

void updateMax(ll index, ll value, ll sz)
{
    SegmentTreeMax[sz + index] = value;

    for(ll x = (sz + index) / 2 ; x > 0 ; x /= 2)
        SegmentTreeMax[x] = max(SegmentTreeMax[2*x], SegmentTreeMax[2*x + 1]);
}

void updateRMax(ll current, ll low, ll high, ll lowest, ll highest, ll value)
{
    if(lowest <= low && highest >= high)
    {
        SegmentTreeMax[current] = value;
        return;
    }
 
    if(low > highest || high < lowest)
        return;
 
    ll middle = low + ((high - low) >> 1);
 
    updateR(2*current, low, middle, lowest, highest, value);
    updateR(2*current + 1, middle + 1, high, lowest, highest,value);

    SegmentTreeMax[current] = max(SegmentTreeMax[2*current], SegmentTreeMax[2*current + 1]);
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
    
    buildMax(data, input);

    while(queries--)
    {
        ll t, l, r;

        cin >> t >> l >> r;

        if(t == 2)
            cout << answerMax(1, 1, input, l, r) << endl;
        else
            updateRMax(1,1,input,l,l,r);
    }

    return 0;
}
