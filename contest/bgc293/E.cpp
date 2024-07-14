#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

constexpr ll C = 1000000;

ll a, x, m;

ll Pow(ll b, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = (res * b) % m;
        n >>= 1;
        b = (b * b) % m;
    }
    return res;
}

int main(){
    cin >> a >> x >> m;

    ll cycle = 0, tmp = 1;
    for(ll i = 0; i < C; i ++){
        cycle = (cycle + tmp) % m;
        tmp = (tmp * a) % m;
    }

    ll res = 0, index = 0;
    for(; index + C < x; index += C){
        res = (res + (Pow(a, index) * cycle) % m) % m;
    }
    tmp = Pow(a, index);
    for(; index < x; index ++){
        res = (res + tmp) % m;
        tmp = (tmp * a) % m;
    }
    cout << res << endl;

}