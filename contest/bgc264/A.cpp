#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int l, r;
    cin >> l >> r;
    string s = "atcoder";
    for(int i = l; i <= r; i ++){
        cout << s[i - 1];
    }
}