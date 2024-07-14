#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll CountBit(ll n){
    ll res = 0;
    while(n > 0){
        res ++;
        n /= 2;
    }
    return res;
}

ll Pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

bool Check(ll n, ll b){
    while(n > 0){
        if(n % b > 1) return false;
        n /= b;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++){
        ll n;
        cin >> n;
        
        ll res = 0;
        for(ll d = 2; d <= CountBit(n); d ++){
            ll left = 2, right = n + 1, min_b, max_b;
            while(left + 1 < right){
                ll mid = left + (right - left) / 2;
                if(Pow(mid, d - 1) <= n) left = mid;
                else right = mid;
            }
            max_b = left;

            left = 1, right = n;
            while(left + 1 < right){
                ll mid = left + (right - left) / 2, tmp = 0;
                for(int j = 0; j < d; j ++) tmp += Pow(mid, j);
                if(tmp >= n) right = mid;
                else left = mid;
            } 
            min_b = right;
      
            for(ll b = min_b; b <= max_b; b ++){
                if(Check(n, b)) res ++;
            }

            // printf("d:%ld ,min_b:%ld, max_b:%ld\n", d, min_b, max_b);
        }
        cout << res << endl;
    }
}