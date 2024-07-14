#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

static constexpr ll mod = 998244353;
ll dp[101][1001][1001], A[1001][1001], B[1001][1001];

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> p(n + 1), q(n + 1);
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for(int i = 1; i <= n; i ++) cin >> q[i];

    ll res = 0;

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i ++){
        memset(A, 0, sizeof(A));    
        memset(B, 0, sizeof(B));    
        for(int x = 0; x <= d; x ++){
            for(int y = 0; y <= d; y ++){
                A[x][y] = dp[i - 1][x][y];
                if(x != 0 and y != 0) A[x][y] = (A[x][y] + A[x - 1][y - 1]) % mod;
            }
        }

        for(int x = 0; x <= d; x ++){
            for(int y = d; y >= 0; y --){
                B[x][y] = dp[i - 1][x][y];
                if(x != 0 and y != d) B[x][y] = (B[x][y] + B[x - 1][y + 1]) % mod;
            }
        }

        int t = abs(p[i] - q[i]);
        for(int x = 0; x <= d; x ++){
            for(int y = 0; y <= d; y ++){
                //  A Section
                if(x - 1 >= 0 and y - t - 1 >= 0) dp[i][x][y] = (dp[i][x][y] + A[x - 1][y - t - 1]) % mod;
                //  C Section
                if(x - t - 1 >= 0 and y - 1 >= 0) dp[i][x][y] = (dp[i][x][y] + A[x - t - 1][y - 1]) % mod;
                // B Section
                ll tmp = 0;
                if(y - t >= 0) tmp = (tmp + B[x][y - t]) % mod;
                else if(x + y - t >= 0) tmp = (tmp + B[x + y - t][0]) % mod;
                if(x - t - 1 >= 0 and y + 1 <= d) tmp = (tmp - B[x - t - 1][y + 1]) % mod;
                dp[i][x][y] = (dp[i][x][y] + tmp) % mod;

                if(i == n) res = (res + dp[i][x][y]) % mod;
            }
        }
    }

    cout << (res + mod) % mod << endl;
}