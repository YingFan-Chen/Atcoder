#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int f(int n, int m, int digit, vector<pair<int, int>> &v){
    int tmp;
    if(n == 1) tmp = digit % m;
    else tmp = (10 * f(n - 1, m, digit, v) + digit) % m;
    if(tmp == 0) v.push_back({n, digit});
    return tmp;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for(int i = 1; i <= 9; i ++){
        f(n, m, i, v);
    }
    sort(v.begin(), v.end());
    if(v.size() == 0){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= v.rbegin()->first; i ++){
        cout << v.rbegin()->second;
    }
    cout << endl;
}