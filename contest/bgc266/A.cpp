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
    int n = s.size();
    cout << s[n / 2] << endl;
}