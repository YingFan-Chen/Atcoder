#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;
static constexpr ll mod = 998244353;

/*
    module can't do divide.
*/

ll f(ll a, ll b, ll c, ll d, ll m){
    if((a + c) % 2) c = c + 1;
    if((a + d) % 2) d = d - 1;
    if(c > d) return 0;

    ll x = ((a - 1) * m + c) % mod, n = (d - c) / 2 + 1;
    x = ((x * n) % mod + ((n - 1) * n) % mod) % mod;

    if((b + c) % 2) b = b - 1;
    ll k = (b - a) / 2 + 1;
    x = ((x * k) % mod + (k - 1) * k % mod * m % mod * n % mod) % mod;
    return x;
}

int main(){
    ll n, m;
    cin >> n >> m;
    int q; cin >> q;
    vector<vector<ll>> query;
    for(int i = 0; i < q; i ++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        query.push_back({a, b, c, d});
    }

    for(int i = 0; i < q; i ++){
        ll a = query[i][0], b= query[i][1], c = query[i][2], d = query[i][3];
        ll res = f(a, b, c, d, m);
        if(a < b) res = (res + f(a + 1, b, c, d, m)) % mod;
        cout << res << endl;
    }
}