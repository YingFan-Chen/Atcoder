#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

/*
    1. Path is white or black.
    2. dp for a square with row-reverse or not and column-reverse or not.
       4 type -> (0, 0), (0, 1), (1, 0), (1, 1).
*/

int main(){
    int h, w;
    cin >> h >> w;
    vector<ll> r(h + 1), c(w + 1);
    for(int i = 1; i <= h; i ++) cin >> r[i];
    for(int i = 1; i <= w; i ++) cin >> c[i];
    int A[h + 1][w + 1];
    memset(A, 0, sizeof(A));
    for(int i = 1; i <= h; i ++){
        string tmp;
        cin >> tmp;
        for(int j = 1; j <= w; j ++){
            A[i][j] = tmp[j - 1] - '0';
        }
    }

    ll dp[h + 1][w + 1][2][2];
    ll res = ll_max;
    
    for(int color = 0; color < 2; color ++){
        memset(dp, 0xFF, sizeof(dp));

        for(int x = 0; x < 2; x ++){
            for(int y = 0; y < 2; y ++){
                if(color ^ A[1][1] ^ x ^ y){
                    dp[1][1][x][y] = ll_max;
                }else{
                    ll tmp = 0;
                    if(x) tmp += r[1];
                    if(y) tmp += c[1];
                    dp[1][1][x][y] = tmp;
                }
            }
        }

        for(int i = 1; i <= h; i ++){
            for(int j = 1; j <= w; j ++){
                for(int x = 0; x < 2; x ++){
                    for(int y = 0; y < 2; y ++){
                        if(i != 1){
                            if(dp[i][j][x][y] < 0) dp[i][j][x][y] = ll_max;
                            if(color ^ A[i][j] ^ x ^ y == 0){
                                ll tmp = ll_max;
                                tmp = min(tmp, dp[i - 1][j][0][y]);
                                tmp = min(tmp, dp[i - 1][j][1][y]);
                                if(tmp == ll_max) dp[i][j][x][y] = min(dp[i][j][x][y], ll_max);
                                else{
                                    if(x) tmp += r[i];
                                    dp[i][j][x][y] = min(dp[i][j][x][y], tmp);
                                }
                            }
                        }
                        if(j != 1){
                            if(dp[i][j][x][y] < 0) dp[i][j][x][y] = ll_max;
                            if(color ^ A[i][j] ^ x ^ y == 0){
                                ll tmp = ll_max;
                                tmp = min(tmp, dp[i][j - 1][x][0]);
                                tmp = min(tmp, dp[i][j - 1][x][1]);
                                if(tmp == ll_max) dp[i][j][x][y] = min(dp[i][j][x][y], ll_max);
                                else{
                                    if(y) tmp += c[j];
                                    dp[i][j][x][y] = min(dp[i][j][x][y], tmp);
                                }
                            }
                        }
                    }
                }
            }
        }

        for(int x = 0; x < 2; x ++){
            for(int y = 0; y < 2; y ++){
                res = min(res, dp[h][w][x][y]);
            }
        }
    }
    
    cout << res << endl;
}