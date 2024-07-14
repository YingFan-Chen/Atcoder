#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

static constexpr ll mod = 998244353;

/* 
    Choose one side -> Catalan Number
*/

ll Pow(ll base, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = (res * base) % mod;
        n >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

int main(){
    ll n;
    cin >> n;

    ll res = Pow(2, n);

    for(ll i = 2 * n; i >= n + 2; i --){
        res = (res * i) % mod;
    }

    cout << res << endl;
}