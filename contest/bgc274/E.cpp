#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int n, m;
pair<ll, ll> pos[17];
bitset<17> Visit; 
unordered_map<ll, double> dp;

double MIN(double a, double b){
    if(a == 0) return b;
    if(b == 0) return a;
    return a < b ? a : b;
}

double Cost(ll x1, ll y1, ll x2, ll y2, int speed){
    double step = pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
    return step / (double) speed;
}

bool Check(){
    bool res = true;
    for(int i = 0; i < n; i ++){
        if(Visit[i] == false) res = false;
    }
    return res;
}

double DFS(int k, int speed){
    ll t = Visit.to_ulong() + k * (1 << 17);
    if(dp[t] != 0) return dp[t];
    
    double res = 0;
    ll x = pos[k].first, y = pos[k].second;
    Visit[k] = true;
    if(k >= 12) speed *= 2;
    for(int i = 0; i < n; i ++){
        if(Visit[i] == false){
            double tmp = DFS(i, speed);
            tmp += Cost(x, y, pos[i].first, pos[i].second, speed);
            res = MIN(res, tmp);
        }
    }
    for(int i = 0; i < m; i ++){
        if(Visit[i + 12] == false){
            double tmp = DFS(i + 12, speed);
            tmp += Cost(x, y, pos[i + 12].first, pos[i + 12].second, speed);
            res = MIN(res, tmp);
        }
    }

    if(Check()){
        res = MIN(res, Cost(x, y, 0, 0, speed));
    }
    Visit[k] = false;
    dp[t] = res;
    return res;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        ll x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }
    for(int i = 0; i < m; i ++){
        ll x, y;
        cin >> x >> y;
        pos[i + 12] = {x, y};
    }

    double res = 0;
    for(int i = 0; i < n; i ++){
        double tmp = DFS(i, 1);
        tmp += Cost(0, 0, pos[i].first, pos[i].second, 1);
        res = MIN(res, tmp);
    }
    for(int i = 0; i < m; i ++){
        double tmp = DFS(i + 12, 1);
        tmp += Cost(0, 0, pos[i + 12].first, pos[i + 12].second, 1);
        res = MIN(res, tmp);
    }
    printf("%.8f\n", res);
}