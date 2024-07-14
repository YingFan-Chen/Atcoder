#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll Pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

void f(vector<ll> &dp, int l, int r, int depth, int n, vector<vector<ll>> &C){
    if(depth == n) return;
    int mid = (l + r) >> 1;
    f(dp, l, mid, depth + 1, n, C);
    f(dp, mid + 1, r, depth + 1, n, C);

    ll left = 0, right = 0;
    for(int i = l; i <= mid; i ++){
        left = max(left, dp[i] + C[i][n - depth]);
    }
    for(int i = mid + 1; i <= r; i ++){
        right = max(right, dp[i] + C[i][n - depth]);
    }

    for(int i = l; i <= mid; i ++){
        dp[i] += right;
    }
    for(int i = mid + 1; i <= r; i ++){
        dp[i] += left;
    }    
}

int main(){
    int n, m;
    cin >> n;
    m = Pow(2, n);

    vector<vector<ll>> C(m + 1, vector<ll> (n + 1));
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++)
            cin >> C[i][j];
    }

    vector<ll> dp(m + 1);
    f(dp, 1, m, 1, n, C);
    
    ll res = 0;
    for(int i = 1; i <= m; i ++){
        res = max(res, dp[i] + C[i][n]);
    }
    cout << res << endl;
}