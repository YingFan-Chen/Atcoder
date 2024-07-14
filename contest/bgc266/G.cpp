#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

static constexpr ll mod = 998244353, kN = 1'000'000;
ll fac[4 * kN + 1], invfac[4 * kN  + 1];

ll Pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = (res * x) % mod;
        n >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

void setup(){
    fac[0] = fac[1] = 1;
    invfac[0] = invfac[1] = 1;
    for(int i = 2; i <= 4 * kN; i ++){
        fac[i] = (fac[i - 1] * i) % mod;
        invfac[i] = Pow(fac[i], mod - 2);
    } 
}

int main(){
    int r, g, b, k;
    cin >> r >> g >> b >> k;
    
    setup();
    ll res = (fac[r - k + b + k] * invfac[r - k]) % mod;
    res = (res * invfac[b]) % mod;
    res = (res * invfac[k]) % mod;

    res = (res * fac[b + g]) % mod;
    res = (res * invfac[g - k]) % mod;
    res = (res * invfac[b + k]) % mod;
    cout << res << endl;
}