#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    ll x, k;
    cin >> x >> k;
    ll tmp = 1;
    for(int i = 1; i <= k; i ++){
        tmp *= 10;
        ll r = x % tmp;
        if(r >= tmp / 2){
            x = (x / tmp + 1) * tmp;
        }else{
            x = (x / tmp) * tmp;
        }
    }
    cout << x << endl;
}