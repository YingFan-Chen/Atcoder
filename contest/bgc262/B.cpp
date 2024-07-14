#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "C:\Users\josep\code\c++\lib\debug"
#endif
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    bool edge[n + 1][n + 1];
    memset(edge, 0, sizeof(edge));
    for(int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        edge[u][v] = true;
        edge[v][u] = true;
    }
    int res = 0;
    for(int a = 1; a < n - 1; a ++){
        for(int b = a + 1; b < n; b ++){
            for(int c = b + 1; c <= n; c ++){
                if(edge[a][b] and edge[b][c] and edge[a][c]) res ++;
            }
        }
    }
    cout << res << endl;
}