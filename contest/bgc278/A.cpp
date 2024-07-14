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
    vector<int> v(n);
    for(int i = 0; i < n; i ++) cin >> v[i];
    for(int i = k; i < n; i ++) cout << v[i] << " ";
    for(int i = 0; i < min(n, k); i ++) cout << "0" << " ";
    cout << endl;
}