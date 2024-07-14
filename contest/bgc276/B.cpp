#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> city(n + 1);
    for(int i = 1; i <= m; i ++){
        int a, b;
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }
    for(int i = 1; i <= n; i ++){
        cout << city[i].size() << " ";
        sort(city[i].begin(), city[i].end());
        for(auto j : city[i]) cout << j << " ";
        cout << endl;
    }
}