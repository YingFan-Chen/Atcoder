#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v(n + 1);
    for(int i = 1; i <= n; i ++){
        int l;
        cin >> l;
        for(int j = 1; j <= l; j ++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    vector<pair<int, int>> query;
    for(int i = 1; i <= q; i ++){
        int s, t;
        cin >> s >> t;
        query.push_back({s, t});
    }
    for(auto [s, t] : query){
        cout << v[s][t - 1] << endl;
    }
}