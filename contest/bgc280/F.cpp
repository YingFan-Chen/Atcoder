#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

vector<pair<int, ll>>> edge[100001], graph;
bool visit[100001];

int DFS(int root){

}

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }

    
}