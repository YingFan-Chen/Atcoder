#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif

using namespace std;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll res;

    if(2 * b >= a + c){
        res = 2 * b - a - c;
    }else{
        res = ((a + c) >> 1) - b;
        if((a + c) & 1){
            res += 2;
        }
    }

    cout << res << endl;
}