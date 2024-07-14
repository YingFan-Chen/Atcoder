#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll ABS(ll x){
    if(x < 0) return -x;
    else return x;
}

ll GCD(ll x, ll y){
    if(x < y) swap(x, y);
    while(x % y){
        x %= y;
        swap(x, y);
    }
    return y;
}

pair<ll, ll> Min(pair<ll, ll> x, pair<ll, ll> y){
    if(x.first < y.first){
        return x;
    }else if(x.first == y.first){
        if(x.second <= y.second){
            return x;
        }else{
            return y;
        }
    }else{
        return y;
    }
}

/*
static constexpr ll mod = 1'000'000'000 + 7;
ll Hash(ll x, ll y){
    x -= y;
    ll res = 17 * x + 35 * y + 67 * (x * x % mod) + 59 * (y * y % mod);
    return res % mod;
}
*/

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> dot;
    for(int i = 0; i < n; i ++){
        ll x, y;
        cin >> x >> y;
        dot.push_back({x, y});
    }

    if(k == 1){
        cout << "Infinity" << endl;
        return 0;
    } 

    set<vector<ll>> s;
    for(int i = 0; i < n; i ++){
        auto [x1, y1] = dot[i];
        map<pair<ll, ll>, ll> count;
        map<pair<ll, ll>, pair<ll, ll>> mini;

        for(int j = 0; j < n; j ++){
            if(i == j) continue;
            auto [x2, y2] = dot[j];
            ll x = x2 - x1, y = y2 - y1;
            if(x == 0){
                x = 0;
                y = 1;
            }else if(y == 0){
                x = 1;
                y = 0;
            }else{
                ll g = GCD(ABS(x), ABS(y));
                if((x ^ y) >= 0){
                    x = ABS(x) / g;
                    y = ABS(y) / g;
                }else{
                    x = ABS(x) / g;
                    y = - ABS(y) / g;
                }
            }
            
            if(count.find({x, y}) == count.end()){
                count[{x, y}] = 2;
                mini[{x, y}] = Min({x1, y1}, {x2, y2});
            }else{
                count[{x, y}] ++;
                mini[{x, y}] = Min(mini[{x, y}], {x2, y2});
            }
        }

        for(auto &l : count){
            if(l.second >= k){
                auto [x, y] = l.first;
                auto [a, b] = mini[{x, y}];
                s.insert({x, y, a, b});
            }
        }

    }

    cout << s.size() << endl;
}