#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

// range 1 ~ i, choose j items, max mod(0 ~ 99) 
ll dp[101][101][101];

int main(){
    int k_, n, d;
    cin >> n >> k_ >> d;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int i = 0; i < 101; i ++)
        for(int j = 0; j < 101; j ++)
            for(int k = 0; k < 101; k ++)
                dp[i][j][k] = -1;

    for(int i = 1; i <= n; i ++){
        ll tmp = a[i];
        for(int j = 1; j <= k_; j ++){
            for(int k = 0; k < d; k ++){
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                if(dp[i - 1][j - 1][k] != -1) 
                    dp[i][j][(dp[i - 1][j - 1][k] + tmp) % d] = max(dp[i][j][(dp[i - 1][j - 1][k] + tmp) % d], dp[i - 1][j - 1][k] + tmp); 
            }
            if(j == 1) dp[i][j][tmp % d] = max(dp[i][j][tmp % d], tmp);
        }
    }

    cout << dp[n][k_][0] << endl;
}