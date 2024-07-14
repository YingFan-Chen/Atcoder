#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll a, b;

double f(ll k){
    double res = b * k + (double) a / (double) pow(1 + k, 0.5);
    return res; 
}


int main(){
    cin >> a >> b;
    ll l = 0, r = a / b;
    while(l + 10 < r){
        ll m1 = l + (r - l) / 3;
        ll m2 = l + 2 * (r - l) / 3;
        if(f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    double res = f(l);
    for(ll i = l; i <= r; i ++) res = min(res, f(i));
    printf("%.7lf\n", res);
}