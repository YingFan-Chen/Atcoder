#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "C:\Users\josep\code\c++\lib\debug"
#endif
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    ll res = 0, equal = 0;

    for(int i = 1; i <= n; i ++){
        if(a[i] == i) equal ++;
        else if(a[i] > i){
            if(a[a[i]] == i) res ++;
        }
    }

    res += equal * (equal - 1) / 2;
    cout << res << endl;
}