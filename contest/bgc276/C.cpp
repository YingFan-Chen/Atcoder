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
    prev_permutation(p.begin(), p.end());
    for(auto i : p) cout << i << " ";
    cout << endl;
}