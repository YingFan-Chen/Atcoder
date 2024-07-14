#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll dp[3001][3001];

int main(){
    ll n, p;
    cin >> n >> p;

    for(int i = 0; i <= n; i ++) dp[i][0] = 1;

    for(int i = 1; i <= n; i ++){
        for(int j = 2; j <= n; j ++){
            ll a = 0, b = 0, c = 0, d = 0;
            if(i >= 10){
                a = dp[i - 1][j - 2] - dp[i - 10][j - 2];
            }else{
                a = dp[i - 1][j - 2]; 
            }
            if(j - 2 == 0) a *= 26;
            else a *= 25;

            if(i >= 10 and j >= 3){
                if(i >= 100){
                    b = dp[i - 10][j - 3] - dp[i - 100][j - 3];
                }else{
                    b = dp[i - 10][j - 3];
                }
                if(j - 3 == 0) b *= 26;
                else b *= 25; 
            }
            
            if(i >= 100 and j >= 4){
                if(i >= 1000){
                    c = dp[i - 100][j - 4] - dp[i - 1000][j - 4];
                }else{
                    c = dp[i - 100][j - 4];
                }
                if(j - 4 == 0) c *= 26;
                else c *= 25;
            }

            if(i >= 1000 and j >= 5){
                if(j - 5 == 0) d = 26 * dp[i - 1000][j - 5];
                else d = 25 * dp[i - 1000][j - 5];
            }

            dp[i][j] = (a + b + c + d + dp[i - 1][j]) % p; 
        }
    }

    ll res = 0;
    for(int i = 0; i < n; i ++){
        res += dp[n][i] - dp[n - 1][i];
    }
    res = (res % p + p) % p;

    cout << res << endl;
}