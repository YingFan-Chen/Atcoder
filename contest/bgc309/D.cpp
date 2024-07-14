#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    unordered_map<int, vector<int>> um;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        um[a].push_back(b);
        um[b].push_back(a);
    }

    int max1 = 0, max2 = 0;
    vector<int> dist(n1 + n2 + 1, -1);
    queue<pair<int, int>> q;

    q.push({1, 0});
    while(q.size()){
        auto [x, y] = q.front();
        q.pop();
        dist[x] = y;
        max1 = y;
        for(auto t : um[x]){
            if(dist[t] == -1){
                dist[t] = 0;
                q.push({t, y + 1});
            }
        }
    }

    q.push({n1 + n2, 0});
    while(q.size()){
        auto [x, y] = q.front();
        q.pop();
        dist[x] = y;
        max2 = y;
        for(auto t : um[x]){
            if(dist[t] == -1){
                dist[t] = 0;
                q.push({t, y + 1});
            }
        }
    }

    cout << max1 + max2 + 1 << endl;
}