#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> S(n), res(n);
    for(int i = 0; i < n; i ++) cin >> S[i];
    res[0] = S[0];
    for(int i = 1; i < n; i ++) res[i] = S[i] - S[i - 1];
    for(int i = 0; i < n; i ++) cout << res[i] << " ";
    cout << endl;
}