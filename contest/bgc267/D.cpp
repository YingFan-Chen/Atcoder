#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll dp[2005][2005];      //first -> index, second -> count

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> A(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i];
    
    ll res = LLONG_MIN;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= i; j ++){
            ll tmp = dp[i - 1][j - 1] + (j * A[i]);
            
            if(i == j) dp[i][j] = tmp;
            else dp[i][j] = max(tmp, dp[i - 1][j]);
        }
        if(i >= m){
            res = max(res, dp[i][m]);
        }
    }
    cout << res << endl;
}