#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;
static constexpr ll mod = 998244353, kN = 200000 + 1;
ll fac[kN], invfac[kN];

/*
    degree of red point : d = 2 * r + s,
    r -> red to red, s -> red to blue
*/

ll Pow(ll base, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int deg[n + 1];
    memset(deg, 0, sizeof(deg));
    for(int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        deg[u] ++;
        deg[v] ++;
    }

    int even = 0, odd = 0;
    for(int i = 1; i <= n; i ++){
        if(deg[i] & 1) odd ++;
        else even ++;
    }

    memset(fac, 0, sizeof(fac));
    memset(invfac, 0, sizeof(invfac));

    fac[0] = fac[1] = invfac[0] = invfac[1] = 1;
    for(int i = 2; i <= max(odd, even); i ++){
        fac[i] = (fac[i - 1] * i) % mod;
        invfac[i] = (invfac[i - 1] * Pow(i, mod - 2)) % mod;
    }

    ll res = 0;
    for(int i = 0; i <= k; i ++){   // i -> num of even
        int tmp = k - i;
        if(tmp & 1) continue;
        if(even >= i and odd >= tmp){
            ll first = ((fac[even] * invfac[i]) % mod * invfac[even - i]) % mod;
            ll second = ((fac[odd] * invfac[tmp]) % mod * invfac[odd - tmp]) % mod;
            res = (res + (first * second) % mod) % mod;
        }
    }

    cout << res << endl;
}