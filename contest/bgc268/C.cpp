#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i ++) cin >> p[i];
    map<int, int> m;
    for(int i = 0; i < n; i ++){
        vector<int> v = {p[i], (p[i] + 1) % n, (p[i] - 1 + n) % n};
        for(auto j : v){
            if(j >= i) m[j - i] ++;
            else m[n - i + j] ++;
        }
    }
    int res = 0;
    for(auto &[v, c] : m){
        res = max(res, (int)c);
    }
    cout << res << endl;

}