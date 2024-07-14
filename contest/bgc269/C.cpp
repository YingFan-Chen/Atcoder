#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

void f(vector<ll> &v, vector<int> &bit, int i){
    if(i == bit.size()) return ;
    ll tmp = (ll) 1 << bit[i];
    int n = v.size();
    for(int j = 0; j < n; j ++){
        v.push_back(v[j] + tmp);
    }
    f(v, bit, i + 1);
}

int main(){
    ll x;
    cin >> x ;
    vector<ll> v = {0};
    vector<int> bit;
    int i = 0;
    while(x > 0){
        if(x & 1) bit.push_back(i);
        x >>= 1;
        i ++;
    }

    f(v, bit, 0);
    sort(v.begin(), v.end());
    for(auto i : v) cout << i << endl;
}