#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    vector<int> h(n), t(n);
    for(int i = 0; i < n; i ++){
        cin >> h[i] >> t[i];
    }
    vector<vector<string>> dp(105, vector<string> (10105));
    for(int i = 0; i < n; i ++){
        if(i == 0){
            dp[i][h[i]] = "H";
            dp[i][t[i]] = "T";
        }else{
            for(int j = 0; j < 10001; j ++){
                if(dp[i - 1][j] != ""){
                    dp[i][j + h[i]] = dp[i - 1][j] + "H";
                    dp[i][j + t[i]] = dp[i - 1][j] + "T";
                }
            }
        }
    }
    if(dp[n - 1][s] != ""){
        cout << "Yes" << endl;
        cout << dp[n - 1][s] << endl;
    }else{
        cout << "No" << endl;
    }
}