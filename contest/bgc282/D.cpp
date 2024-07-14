#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

vector<int> edges[200001];
int color[200001];
vector<vector<int>> cc;


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i = 1; i <= n; i ++){
        if(color[i] == 0){
            queue<int> q;
            q.push(i);
            color[i] = 1;
            int black = 1, white = 0, count = 0;
            while(q.size()){
                int t = q.front();
                q.pop();
                for(auto j : edges[t]){
                    count ++;
                    if(color[j] == 0){
                        if(color[t] == 1){
                            white ++;
                            color[j] = 2;
                        }else{
                            black ++;
                            color[j] = 1;
                        }
                        q.push(j);
                    }else if(color[j] == color[t]){
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
            cc.push_back(vector<int> {black, white, count});
        }
    }

    ll res = 0, half = 0;
    for(auto &v : cc){
        ll black = v[0], white = v[1], count = v[2];
        res += black * white - count / 2;
        half += (n - black - white) * (black + white); 
    }
    cout << res + half / 2 << endl;
}