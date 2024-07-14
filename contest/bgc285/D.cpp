#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;
 
unordered_map<string, vector<string>> edge;
unordered_map<string, bool> visited;
 
bool DFS(string s){
    visited[s] = true;
    if(edge[s].size() == 1){
        string a = edge[s][0];
        if(visited[a] == true) return true;
        else return DFS(a);
    }else{
        string a = edge[s][0], b = edge[s][1];
        if(visited[a] == true and visited[b] == true) return false;
        if(visited[a] == false){
            if(DFS(a) == false) return false;
        }
        if(visited[b] == false){
            if(DFS(b) == false) return false;
        }
        return true;
    }
}
 
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        string s, t;
        cin >> s >> t;
        edge[s].push_back(t);
        edge[t].push_back(s);
        visited[s] = false;
        visited[t] = false;
    }
 
    for(auto &[s, visit] : visited){
        if(visit == false){
            if(DFS(s) == false){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}