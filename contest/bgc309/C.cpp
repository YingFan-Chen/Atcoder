#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v;
    ll total = 0;
    for(int i = 0; i < n; i ++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        total += b;
    }

    sort(v.begin(), v.end());

    if(total <= k){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i ++){
        total -= v[i].second;
        if(total <= k){
            cout << v[i].first + 1 << endl;
            return 0;
        }
    }
}