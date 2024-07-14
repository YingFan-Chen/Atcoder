#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    string s;
    cin >> s;
    ll res = 0;
    for(int i = 0; i < s.size(); i ++){
        res = res * 26 + s[i] - 'A' + 1;
    }
    cout << res << endl;
}