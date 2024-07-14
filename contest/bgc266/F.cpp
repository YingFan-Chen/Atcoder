#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int Find_Loop(vector<vector<int>> &edge, set<int> &loop, set<int> &s, int cur, int from){
    if(s.find(cur) != s.end()){
        loop.insert(cur);
        return cur;
    }

    s.insert(cur);
    for(auto i : edge[cur]){
        if(i != from){
            int x = Find_Loop(edge, loop, s, i, cur);
            if(x != 0){
                loop.insert(cur);
                if(x == cur) return 0;
                else return x;
            }
        }
    }
    return 0;
}

void DFS(vector<vector<int>> &edge, set<int> &loop, set<int> &s, vector<int> &belong, int cur, int from){
    if(s.find(cur) != s.end()) return ;

    s.insert(cur);
    if(loop.find(cur) != loop.end()){
        belong[cur] = cur;
    }else{
        belong[cur] = belong[from];
    }
    for(auto i : edge[cur]){
        if(i != from){
            DFS(edge, loop, s, belong, i, cur);
        }
    }
}

int main(){
    int n; 
    cin >> n;
    vector<vector<int>> edge(n + 1);
    for(int i = 0; i < n; i ++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int q;
    cin >> q;
    vector<pair<int, int>> query;
    for(int i = 0; i < q; i ++){
        int x, y;
        cin >> x >> y;
        query.push_back({x, y});
    }
    set<int> loop, s;
    Find_Loop(edge, loop, s, 1, 0);

    vector<int> belong(n + 1);
    s.clear();
    DFS(edge, loop, s, belong, *loop.begin(), 0);
    for(int i = 0; i < q; i ++){
        auto [x, y] = query[i];
        if(belong[x] == belong[y]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}