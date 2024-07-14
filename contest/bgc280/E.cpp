#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

static constexpr ll mod = 998244353;

ll Pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = (res * x) % mod;
        n >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

int main(){
    int n, p;
    cin >> n >> p;
    vector<ll> E(n + 1);
    ll inverse = Pow(100, mod - 2);
    E[1] = 1;
    for(int i = 2; i <= n; i ++){
        ll t1, t2;
        t1 = (100 - p) * (E[i - 1] + 1) % mod;
        t1 = (t1 * inverse) % mod;
        t2 = p * (E[i - 2] + 1) % mod;  
        t2 = (t2 * inverse) % mod;
        E[i] = (t1 + t2) % mod;
    }
    cout << E[n] << endl;
}