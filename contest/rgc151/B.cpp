#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

static constexpr ll mod = 998244353;
vector<int> edge[200001];
bool v[200001];

void DFS(int x){
    v[x] = true;
    for(auto i : edge[x]){
        if(v[i] == false) DFS(i);
    }
}

ll f(ll x, ll m){
    ll res = 1;
    for(int i = 1; i <= x; i ++) res = (res * m) % mod;
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> P(n + 1);
    for(int i = 1; i <= n; i ++) cin >> P[i];
    for(int i = 1; i <= n; i ++){
        edge[i].push_back(P[i]);
        edge[P[i]].push_back(i);
    }
    int count = 0;
    for(int i = 1; i <= n; i ++){
        if(v[i] == false) DFS(i), count ++;
    }
    ll res = (f(n, m) - f(count, m)) % mod;
    if(res < 0) res += mod;
    cout << res / 2 << endl;
}