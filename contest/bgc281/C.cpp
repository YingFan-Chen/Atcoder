#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    vector<ll> sum(n + 1);
    for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
    t = t % sum[n];
    int l = 0, r = n;
    while(l + 1 < r){
        int mid = l + (r - l) / 2;
        if(sum[mid] >= t) r = mid;
        else l = mid;
    }
    cout << l + 1 << " " << t - sum[l] << endl;
}