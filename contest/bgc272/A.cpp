#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i ++){
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    cout << sum << endl;
}