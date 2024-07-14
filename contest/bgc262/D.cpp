#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "C:\Users\josep\code\c++\lib\debug"
#endif
using namespace std;
constexpr ll mod = 998244353;

/*
    Try to make a 4-degree DP
*/

int main(){
    int n;
    cin >> n;
    ll a[n + 1];
    for(int i = 1; i <= n; i ++) cin >> a[i];

    ll dp[n + 1][n + 1][n + 1][n + 1];     // first -> a[i], second -> num of a, third -> mod, fourth -> remainder
    memset(dp, 0, sizeof(dp));
    
    ll res = 0;

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= i; j ++){
            for(int k = 1; k <= n; k ++){
                if(j == 1)
                    dp[i][j][k][a[i] % k] = (dp[i][j][k][a[i] % k] + 1) % mod;
                for(int l = 0; l < k; l ++){
                    ll tmp = ((l - a[i]) % k + k) % k;
                    dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j][k][l] + dp[i - 1][j - 1][k][tmp]) % mod;
                }
            }
        }
    } 
    
    for(int i = 1; i <= n; i ++){
        res = (res + dp[n][i][i][0]) % mod;
    }

    cout << res << endl;
}