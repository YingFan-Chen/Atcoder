#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

void DFS(int x, int y, set<pair<int, int>> &s, set<pair<int, int>> &go){
    if(s.find({x, y}) == s.end() or go.find({x, y}) != go.end()) return ;
    go.insert({x, y});
    DFS(x - 1, y - 1, s, go);
    DFS(x - 1, y, s, go);
    DFS(x, y - 1, s, go);
    DFS(x, y + 1, s, go);
    DFS(x + 1, y, s, go);
    DFS(x + 1, y + 1, s, go);
}

int main(){
    int n; cin >> n;
    set<pair<int, int>> s;
    for(int i = 0; i < n; i ++){
        int x, y; cin >> x >> y;
        s.insert({x, y});
    }

    int count = 0;
    set<pair<int, int>> go;
    for(auto &i : s){
        if(go.find(i) == go.end()) DFS(i.first, i.second, s, go), count ++;
    }
    cout << count << endl;
}