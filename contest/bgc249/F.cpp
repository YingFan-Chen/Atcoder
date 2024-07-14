#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i ++){
        ll t, y;
        cin >> t >> y;
        v.push_back({t, y});
    }
    priority_queue<ll> pq;
    vector<ll> positive(n + 1);
    for(int i = n - 1; i >= 0; i--){
        ll t = v[i].first, y = v[i].second;
        if(t == 2 and y >= 0) positive[i] = positive[i + 1] + y;
        else positive[i] = positive[i + 1];
    }
    ll res = LLONG_MIN, negative = 0;
    for(int i = n - 1; i >= 0; i --){
        ll t = v[i].first, y = v[i].second;
        if(t == 2 and y < 0){
            pq.push(y);
            k --;
        }else if(t == 1){
            //printf("i : %d k : %lld y : %lld pos : %lld neg : %lld\n", i, k, y, positive[i], negative);
            if(k >= 0) res = max(res, y + positive[i] + negative);
            k --;
        }
        if(k < 0 and pq.size()){
            k ++;
            negative += pq.top();
            pq.pop();
        }
    }
    if(k >= 0) res = max(res, positive[0] + negative);
    cout << res << endl;
}