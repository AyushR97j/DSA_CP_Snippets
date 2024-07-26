#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 7;
const ll maxn = N;

struct fenwick
{
    ll BIT[maxn];

    // it should be 1 based if not then inc i
    ll query(ll i)
    {
        i++;
        ll sum = 0;
        while (i > 0)
        {
            sum = sum + BIT[i];
            i = i - (i & -i);
        }
        return sum;
    }

    void update(ll i, ll val)
    {
        i++;

        // if(i<1) return;
        while (i <= maxn)
        {
            BIT[i] = BIT[i] + val;
            i = i + (i & -i);
        }
    }

    void rupdate(ll l, ll r, ll val)
    {
        update(l, val);
        update(r + 1, -val);
    }

} fenw;

int main()
{
    cout << "Fenwick Tree";

    vector<ll> v = {6, -2, 9, 10, -8, 1, 0, 6, 4, -2};
    for(int i = 0; i < v.size(); i++) {
        fenw.update(i, v[i]);
    }

    cout<<fenw.query(10);

    return 0;
}