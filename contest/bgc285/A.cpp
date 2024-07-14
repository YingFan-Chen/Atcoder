#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(a * 2 == b or a * 2 + 1 == b) cout << "Yes" << endl;
    else cout << "No" << endl;
}