#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;
 
int ABS(int x){
    if(x >= 0) return x;
    else return -x;
}
 
ll f(vector<int> &p, int offset, int n){
    ll res = 0;
    for(int i = 0; i < p.size(); i ++){
        int tmp = ABS(p[i] - offset) % n;
        res += min(tmp, n - tmp);
    }
    return res;
}
 
int main(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i ++) cin >> p[i];
 
    for(int i = 0; i < n; i ++){
        p[i] -= i;
    }

    ll res = ll_max;
    vector<pair<int, int>> v = {{0, n / 8}, {n / 8, 2 * n / 8}, {2 * n / 8, 3 * n / 8}, {3 * n / 8,  4 * n / 8},
                                {4 * n / 8, 5 * n / 8}, {5 * n / 8, 6 * n / 8}, {6 * n / 8, 7 * n / 8}, {7 * n / 8,  8 * n / 8}};

    for(auto [l , r] : v){
        while(l + 5 < r){
            int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
            if(f(p, m1, n) < f(p, m2, n)) r = m2;
            else l = m1;
        }
        for(int i = l; i <= r; i ++){
            res = min(res, f(p, i, n));
        }
    }
 
    cout << res << endl;
}