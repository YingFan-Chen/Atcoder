#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, x, y;
    cin >> x >> y >> n;
    int res = 0;
    res += (n / 3) * y;
    res += (n % 3) * x;

    res = min(res, n * x);
    cout << res << endl;
}