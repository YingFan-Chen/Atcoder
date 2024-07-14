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
    vector<int> dp(5 * n);
    for(int i = 1; i <= n; i ++){
        int k;
        cin >> k;
        dp[2 * i] = dp[2 * i + 1] = dp[k] + 1;
    }
    for(int i = 1; i <= 2 * n + 1; i ++){
        cout << dp[i] << endl;
    }
}