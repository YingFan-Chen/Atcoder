#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll edges[501][501];
ll m;

ll pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin >> n >> m;
    vector<ll> A(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i != j) edges[i][j] = (pow(A[i], A[j]) + pow(A[j], A[i])) % m;
        }
    
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    unordered_set<int> s;
    
    ll sum = 0;
    s.insert(1);
    for(int i = 1; i <= n; i ++) pq.push({edges[1][i], i});
    while(pq.size()){
        auto [weight, node] = pq.top();
        pq.pop();
        if(s.find(node) == s.end()){
            s.insert(node);
            sum += weight;
            for(int i = 1; i <= n; i ++) pq.push({edges[node][i], i});
        }
    }
    cout << sum << endl;
}