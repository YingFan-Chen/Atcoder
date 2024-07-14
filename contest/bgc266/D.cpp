#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n;
    cin >> n;
    int snuke[100001][5];
    memset(snuke, 0, sizeof(snuke));
    for(int i = 1; i <= n; i ++){
        int t, x, a;
        cin >> t >> x >> a;
        snuke[t][x] = a;
    }
    
    vector<vector<ll>> dp(100001, vector<ll> (5, - 1));
    dp[0][0] = 0;
    for(int i = 1; i <= 100000; i ++){
        for(int j = 0; j < 5; j ++){
            ll maxi = -1;
            if(j != 0 and dp[i - 1][j - 1] != -1){
                maxi = max(maxi, dp[i - 1][j - 1] + snuke[i][j]);
            }
            if(dp[i - 1][j] != -1){
                maxi = max(maxi, dp[i - 1][j] + snuke[i][j]);
            }
            if(j != 4 and dp[i - 1][j + 1] != -1){
                maxi = max(maxi, dp[i - 1][j + 1] + snuke[i][j]);
            }
            dp[i][j] = maxi;
        }
    }


    ll res = -1;
    for(int i = 0; i < 5; i ++){
        res = max(res, dp[100000][i]);
    }
    //debug(dp);
    cout << res << endl;
}