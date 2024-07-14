#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    ll n;
    cin >> n;
    ll mod = 998244353;
    n = n % mod + mod;
    cout << n % mod << endl;
}