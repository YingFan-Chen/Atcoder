#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int GCD(int a, int b){
    if(a < b) swap(a, b);
    while(a % b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return b;
}


int main(){
    int t; cin >> t;
    vector<ll> res;
    for(int i = 1; i <= t; i ++){
        ll N, D, K;
        cin >> N >> D >> K;

        K --;
        ll n = N / GCD(N, D);
        ll ans = K / n + (K % n * D) % N;
        res.push_back(ans);
    }
    for(auto i : res) cout << i << endl;
}