#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    if (s.find(t) != string::npos) cout << "Yes" << endl;
    else cout << "No" << endl;
}