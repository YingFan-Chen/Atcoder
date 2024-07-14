#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

void DFS(int x, vector<int> &res, vector<int> &go, vector<vector<int>> &edge, int t){
    res.push_back(x);
    go[x] = 1;
    if(x == t){
        for(auto i : res){
            cout << i << " ";
        }
        cout << endl;
        return ;
    }
    for(auto i : edge[x]){
        if(go[i] == 0) DFS(i, res, go, edge, t);
    }
    res.pop_back();
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> edge(n + 1);
    for(int i = 0; i < n - 1; i ++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<int> go(n + 1);
    vector<int> v;
    DFS(x, v, go, edge, y);
}