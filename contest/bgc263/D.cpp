#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, l, r;
    cin >> n >> l >> r;
    vector<ll> A(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i];

    vector<ll> a(n + 1), b(n + 1);

    ll count = 0;
    for(int i = 1; i <= n; i ++){
        count += l - A[i];
        a[i] = count;
    }

    count = 0;
    for(int i = 1; i <= n; i ++){
        count += r - A[n - i + 1];
        b[i] = count;
    }


    ll minVal = 0;
    for(int i = 1; i <= n; i ++){
        minVal = min(minVal, a[i]);
        a[i] = min(minVal, a[i]);
    }


    ll res = 0;
    for(int i = 0; i <= n; i ++){
        ll t;
        t = b[i] + a[n - i];
        res = min(res, t);
    }

    ll sum = 0;
    for(int i = 1; i <= n; i ++){
        sum += A[i];
    }
    cout << sum + res << endl;
}