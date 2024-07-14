#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll k;
const ll N = 1000000;
vector<ll> lp(N+1);
vector<ll> pr;

int f(ll &k, ll p){
    int count = 0;
    while(k % p == 0){
        count ++;
        k /= p;
    }
    return count;
}

int main(){
    cin >> k;
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
    
    ll res = 0;
    for(auto p : pr){
        int count = f(k, p);

        ll r = 0, c = 0;
        while(c < count){
            r ++;
            ll tmp = r;
            c += f(tmp, p);
        }
        res = max(res, r);
    }
    res = max(res, k);
    cout << res << endl;
}