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
    vector<int> A(n + 1);
    vector<ll> sum(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i], sum[i] = sum[i - 1] + A[i] * 2;

    vector<ll> dp(n + 1);
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < i; j ++){
            int tmp = i - j - 1;
            if(tmp % 2){
                dp[i] = max(dp[i], dp[j] + sum[tmp / 2] + A[tmp / 2 + 1]);
            }else{
                dp[i] = max(dp[i], dp[j] + sum[tmp / 2]);
            }
        }
    }
    cout << dp[n] << endl;
}