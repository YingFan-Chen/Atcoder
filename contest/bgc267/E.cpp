#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> A(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i];

    vector<vector<int>> edge(n + 1);
    vector<ll> cost(n + 1);
    for(int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u] += A[v];
        cost[v] += A[u];
    }

    ll res = 0;
    map<ll, vector<int>> mapping;
    for(int i = 1; i <= n; i ++){
        mapping[cost[i]].push_back(i);
    }
    set<int> s;
    for(int i = 1; i <= n; i ++) s.insert(i);
    while(s.size()){
        auto it = mapping.begin();
        auto v = *it->second.rbegin();
        res = max(res, it->first);
        it->second.pop_back();
        if(it->second.empty()) mapping.erase(it);

        s.erase(v);
        for(auto i : edge[v]){
            if(s.find(i) != s.end()){
                ll tmp = cost[i];
                cost[i] -= A[v];
                mapping[tmp].erase(find(mapping[tmp].begin(), mapping[tmp].end(), i));
                if(mapping[tmp].empty()) mapping.erase(tmp);
                mapping[cost[i]].push_back(i);
            }
        }
    }
    cout << res << endl;
}