#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

constexpr int C = 100020;

vector<int> in[C], out[C];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j ++){
            if(s[j] == '1'){
                out[i].push_back(i + j + 1);
                in[i + j + 1].push_back(i);
            }
        }
    }

    queue<pair<int, int>> q;
    vector<int> distFromOrigin(n + 1, -1), distFromEnd(n + 1, -1);
    q.push({1, 0});
    distFromOrigin[1] = 0;
    while(q.size()){
        auto [node, dist] = q.front();
        q.pop();
        for(auto t : out[node]){
            if(distFromOrigin[t] == -1) q.push({t, dist + 1}), distFromOrigin[t] = dist + 1;
        }
    }

    q.push({n, 0});
    distFromEnd[n]  = 0;
    while(q.size()){
        auto [node, dist] = q.front();
        q.pop();
        for(auto t : in[node]){
            if(distFromEnd[t] == -1) q.push({t, dist + 1}), distFromEnd[t] = dist + 1;
        }
    }

    for(int k = 2; k < n; k ++){ 
        int res = INT_MAX;
        for(int i = k - 1; i > max(0, k - m); i --){
            for(auto t : out[i]){
                if(t > k and distFromOrigin[i] != -1 and distFromEnd[t] != -1)
                    res = min(res, distFromOrigin[i] + distFromEnd[t] + 1);
            }
        }
        if(res == INT_MAX) cout << -1 << " ";
        else cout << res << " ";
    }
    cout << endl;
}