#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, a;
    cin >> n >> a;
    vector<int> W(n + 1), X(n + 1), V(n + 1);
    for(int i = 1; i <= n; i ++) cin >> W[i] >> X[i] >> V[i];
    
    int res = 0;
    for(int t = 0; t <= 10000; t ++){
        vector<pair<ll, int>> v;
        for(int i = 1; i <= n; i ++){
            ll x = X[i] + V[i] * t;
            v.push_back({x, W[i]});
        }
        sort(v.begin(), v.end());
        
        int tmp = v[0].second, l = 0, r = 0;
        while(l < n){
            while(r + 1 < n and (v[l].first + a) >= v[r + 1].first){
                r ++;
                tmp += v[r].second;
            }
            res = max(res, tmp);
            tmp -= v[l].second;
            l ++;
        }
    }
    cout << res << endl;
}