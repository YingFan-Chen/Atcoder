#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> A(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i];
    
    ll res = LLONG_MIN;
    vector<ll> sum(n + 1), mult(n + 1);
    for(int i = 1; i <= n; i ++){
        sum[i] = sum[i - 1] + A[i];
        mult[i] = mult[i - 1] + A[i] * i; 
    } 

    for(int i = 1; i + m - 1 <= n; i ++){
        ll tmp = mult[i + m - 1] - mult[i - 1];
        tmp -= (i - 1) * (sum[i + m - 1] - sum[i - 1]);
        res = max(res, tmp); 
    }
    cout << res << endl;
}