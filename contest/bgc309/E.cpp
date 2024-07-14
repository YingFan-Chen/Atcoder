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
    vector<int> fa(n + 1);
    vector<vector<int>> son(n + 1);

    for(int i = 2; i <= n; i ++){
        int tmp;
        cin >> tmp;
        fa[i] = tmp;
        son[tmp].push_back(i);
    }

    vector<int> ins(n + 1, -1);
    for(int i = 0; i < m; i ++){
        int x, y;
        cin >> x >> y;
        ins[x] = max(ins[x], y);
    }

    int res = 0;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int x = q.front();
        q.pop();
        ins[x] = max(ins[x], ins[fa[x]] - 1);
        if(ins[x] >= 0) res ++;
        for(auto t : son[x]){
            q.push(t);
        }
    }
    cout << res << endl;
}