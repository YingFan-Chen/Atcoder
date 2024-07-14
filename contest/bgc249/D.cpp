#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

/*
    Harmonic series = O(logn)
*/

static constexpr int kN = 200'000;

int main(){
    int n; 
    cin >> n;
    vector<ll> count(kN + 1);
    for(int i = 0; i < n; i ++){
        int a;
        cin >> a;
        count[a] ++; 
    }

    ll res = 0;
    for(int i = 1; i <= kN; i ++){
        for(int j = 1; i * j <= kN; j ++){
            res += count[i] * count[j] * count[i * j];
        }
    }

    cout << res << endl;
}