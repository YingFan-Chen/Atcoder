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
    vector<double> dp(n + 1);
    for(int i = 1; i <= n; i ++){
        double exp = 0;
        for(int j = 1; j <= 6; j ++){
            exp += max((double) j, dp[i - 1]);
        }
        dp[i] = exp / 6;
    }
    printf("%.10f\n", dp[n]);
}