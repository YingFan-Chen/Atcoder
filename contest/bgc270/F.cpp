#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll minSpan(vector<vector<pair<ll, ll>>> &edge, ll root, ll count){
    ll res = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    set<ll> s;
    for(auto &i : edge[root]) pq.push({i.second, i.first});
    s.insert(root);
    while(pq.size() and s.size() < count){
        ll dist = pq.top().first, v = pq.top().second;
        pq.pop();
        if(s.find(v) == s.end()){
            for(auto &i : edge[v]) pq.push({i.second, i.first});
            s.insert(v);
            res += dist;
        }
    }
    if(s.size() == count) return res;
    else return -1;
}

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> X(n + 1), Y(n + 1);
    vector<vector<pair<ll, ll>>> Z(n + 3), Z1(n + 3), Z2(n + 3), Z3(n + 3);

    for(int i = 1; i <= n; i ++) cin >> X[i];
    for(int i = 1; i <= n; i ++) cin >> Y[i];
    for(int i = 1; i <= m; i ++){
        ll a, b, z;
        cin >> a >> b >> z;
        Z[a].push_back({b, z});
        Z[b].push_back({a, z});
        Z1[a].push_back({b, z});
        Z1[b].push_back({a, z});
        Z2[a].push_back({b, z});
        Z2[b].push_back({a, z});
        Z3[a].push_back({b, z});
        Z3[b].push_back({a, z});
    }

    ll none, boat, airport, both;
    none = minSpan(Z, 1, n);

    for(int i = 1; i <= n; i ++){
        Z1[n + 1].push_back({i, X[i]});
        Z1[i].push_back({n + 1, X[i]});
        Z3[n + 1].push_back({i, X[i]});
        Z3[i].push_back({n + 1, X[i]});
    }
    for(int i = 1; i <= n; i ++){
        Z2[n + 2].push_back({i, Y[i]});
        Z2[i].push_back({n + 2, Y[i]});
        Z3[n + 2].push_back({i, Y[i]});
        Z3[i].push_back({n + 2, Y[i]});
    }
    boat = minSpan(Z1, 1, n + 1);
    airport = minSpan(Z2, 1, n + 1);
    both = minSpan(Z3, 1, n + 2);
    ll res = ll_max;
    if(none != -1) res = min(res, none);
    if(boat != -1) res = min(res, boat);
    if(airport != - 1) res = min(res, airport);
    if(both != -1) res = min(res, both);
    cout << res << endl;
}