#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

#define kN 200'005

int Fa1[kN][19], depth1[kN], Fa2[kN][19], depth2[kN];

pair<int, int> findLR(vector<vector<int>> &edge){
    set<int> s;
    queue<int> q;
    int l, r;

    s.insert(1);
    q.push(1);
    while(q.size()){
        l = q.front();
        q.pop();
        for(auto i : edge[l]){
            if(s.find(i) == s.end()){
                s.insert(i);
                q.push(i);
            }
        }
    }

    s.erase(l);
    q.push(l);
    while(q.size()){
        r = q.front();
        q.pop();
        for(auto i : edge[r]){
            if(s.find(i) != s.end()){
                s.erase(i);
                q.push(i);
            }
        }
    }
    return {l, r};
}

void DFS1(int x, int fa, vector<vector<int>> &edge){
    depth1[x] = depth1[fa] + 1;
    Fa1[x][0] = x;
    Fa1[x][1] = fa;
    for(int i = 2; i <= 18; i ++){
        Fa1[x][i] = Fa1[Fa1[x][i - 1]][i - 1];
    }
    for(auto i : edge[x]){
        if(depth1[i] == 0) DFS1(i, x, edge);
    }
}

void DFS2(int x, int fa, vector<vector<int>> &edge){
    depth2[x] = depth2[fa] + 1;
    Fa2[x][0] = x;
    Fa2[x][1] = fa;
    for(int i = 2; i <= 18; i ++){
        Fa2[x][i] = Fa2[Fa2[x][i - 1]][i - 1];
    }
    for(auto i : edge[x]){
        if(depth2[i] == 0) DFS2(i, x, edge);
    }
}

int LCAL(int R, int u){
    int d = depth1[R] - depth1[u], count = 1;
    while(d > 0){
        if(d & 1) R = Fa1[R][count];
        count ++;
        d >>= 1;
    }
    while(Fa1[R][0] != Fa1[u][0]){
        for(int i = 18; i >= 0; i --){
            if(Fa1[R][i] != Fa1[u][i]){
                R = Fa1[Fa1[R][i]][1];
                u = Fa1[Fa1[u][i]][1];
                break;
            }
        }
    }
    return R;
}

int LCAR(int L, int u){
    int d = depth2[L] - depth2[u], count = 1;
    while(d > 0){
        if(d & 1) L = Fa2[L][count];
        count ++;
        d >>= 1;
    }
    while(Fa2[L][0] != Fa2[u][0]){
        for(int i = 18; i >= 0; i --){
            if(Fa2[L][i] != Fa2[u][i]){
                L = Fa2[Fa2[L][i]][1];
                u = Fa2[Fa2[u][i]][1];
                break;
            }
        }
    }
    return L;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> edge(n + 1);
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int q; cin >> q;
    vector<pair<int, int>> query;
    for(int i = 0; i < q; i ++){
        int u, k;
        cin >> u >> k;
        query.push_back({u, k});
    }

    auto tmp = findLR(edge);
    int L = tmp.first, R = tmp.second;
    DFS1(L, 0, edge); // L is root
    DFS2(R, 0, edge); // R is root

    for(auto i : query){
        auto [u, k] = i;
        int lca, d, count;
        
        lca = LCAL(R, u);
        d = k - depth1[u] + depth1[lca];
        count = 1;

        if(d <= 0){
            int tmp = k;
            lca = u;
            while(tmp > 0){
                if(tmp & 1) lca = Fa1[lca][count];
                count ++;
                tmp >>= 1;
            }
            cout << lca << endl;
            continue;
        }

        while(d > 0){
            if(d & 1) lca = Fa1[lca][count];
            count ++;
            d >>= 1;
        }
        if(lca != 0){
            cout << lca << endl;
            continue;
        }

        lca = LCAR(L, u);
        d = k - depth2[u] + depth2[lca];
        count = 1;

        if(d <= 0){
            int tmp = k;
            lca = u;
            while(tmp > 0){
                if(tmp & 1) lca = Fa2[lca][count];
                count ++;
                tmp >>= 1;
            }
            cout << lca << endl;
            continue;
        }

        while(d > 0){
            if(d & 1) lca = Fa2[lca][count];
            count ++;
            d >>= 1;
        }
        if(lca != 0){
            cout << lca << endl;
        }else{
            cout << -1 << endl;
        }
    }

}