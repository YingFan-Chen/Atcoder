#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

/*
    To add edges is easier than to erase edges in graph,
    so use reverse order to transform the problem.
    We can regard all the plants as a specific point.
*/ 

struct DS{          //Disjoint set
    vector<int> v;
    DS(int n){
        v.resize(n << 1, -1);
    }
    int query(int x){
        if(v[x] < 0) return x;
        else{
            v[x] = query(v[x]);
            return v[x];
        }
    }
    void merge(int x, int y){
        int a = query(x), b = query(y);
        if(a == b) return;
        else{
            v[a] += v[b];
            v[b] = a;
            return;
        }
    }
    int size(int x){
        int tmp = query(x);
        return - v[tmp];
    }
};

int main(){
    int n, m, e;
    cin >> n >> m >> e;
    vector<pair<int, int>> edge;
    for(int i = 0; i < e; i ++){
        int u, v;
        cin >> u >> v;
        u = min(u, n + 1);
        v = min(v, n + 1);
        edge.push_back({u, v});
    }

    int q;
    cin >> q;
    vector<int> add;
    set<int> s;
    for(int i = 0; i < q; i ++){
        int x;
        cin >> x;
        add.push_back(x - 1);
        s.insert(x - 1);
    }

    vector<int> res;
    DS ds(n);
    for(int i = 0; i < edge.size(); i ++){
        if(s.find(i) == s.end()){
            ds.merge(edge[i].first, edge[i].second);
        }
    }
    int tmp = ds.query(n + 1);
    res.push_back(ds.size(tmp) - 1);
    for(int i = add.size() - 1; i > 0; i --){
        ds.merge(edge[add[i]].first, edge[add[i]].second);
        tmp = ds.query(n + 1);
        res.push_back(ds.size(tmp) - 1);
    }
    
    for(int i = res.size() - 1; i >= 0; i --){
        cout << res[i] << endl;
    }

}