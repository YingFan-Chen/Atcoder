#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "C:\Users\josep\code\c++\lib\debug"
#endif
using namespace std;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll res = 0;

    ll count = n / a, remain = n % a;
    if(count < 1){
        cout << res << endl;
    }else{
        if(a <= b){
            res = n - a + 1;
        }else{
            res = b * (count - 1);
            if(remain >= b) res += b;
            else res += remain + 1;
        }
        cout << res << endl;
    }
}