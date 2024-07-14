#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

constexpr ll mod = 998244353;
constexpr int C = 5000005;

ll fact[C];

ll Pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = (res * x) % mod;
        n >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

ll inv(ll x){
    ll res = Pow(x, mod - 2);
    return res;
}

ll H(ll a, ll b){
    ll res = (fact[a + b] * inv(fact[a]) % mod) * inv(fact[b]) % mod;
    return res;
}

int main(){
    fact[0] = 1;
    for(int i = 1; i < C; i ++){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    int T; cin >> T;
    for(int i = 1; i <= T; i ++){
        ll N; cin >> N;
        ll res = H(N - 2, N - 1) + N * H(N - 3, N - 1);
        cout << res % mod << endl;
    }
}