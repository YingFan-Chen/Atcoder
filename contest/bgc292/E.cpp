#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

vector<int> edges[2001];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    
    vector<int> res(2001);
    for(int i = 1; i <= n; i ++){
        queue<int> q;
        bitset<2001> visit;
        q.push(i);
        visit[i] = true;
        while(q.size()){
            int t = q.front();
            q.pop();
            for(auto j : edges[t]){
                if(visit[j] == false){
                    visit[j] = true;
                    q.push(j);
                    res[i] ++;
                }
            }
        }
    }

    int count = 0;
    for(int i = 1; i <= n; i ++){
        count += res[i] - edges[i].size();
    }
    cout << count << endl;
}