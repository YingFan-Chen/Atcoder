#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(5 * n);
    for(int i = 0; i < 5 * n; i ++) cin >> v[i];
    sort(v.begin(), v.end());
    ll total = 0;
    for(int i = n; i < 4 * n; i ++) total += v[i];
    double res = (double) total / (3 * n);
    printf("%.6f\n", res); 
}