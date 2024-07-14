#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

struct edge{
    int u, v;
    ll w;
    set<int> index;
    edge(int u, int v, ll w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<edge> edges;
    edges.push_back(edge{0, 0, 0});
    for(int i = 1; i <= m; i ++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.push_back(edge{a, b, c});
    }
    vector<ll> path(n + 1, 1E15);
    path[1] = 0;
    for(int i = 0; i < k; i ++){
        int x;
        cin >> x;
        ll newv = path[edges[x].u] + edges[x].w;
        path[edges[x].v] = min(path[edges[x].v], newv);
    }
    if(path[n] == 1E15) cout << -1 << endl;
    else cout << path[n] << endl;
}