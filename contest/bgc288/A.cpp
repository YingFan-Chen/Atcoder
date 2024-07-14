#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
}