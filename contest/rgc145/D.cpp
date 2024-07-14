#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

/* 
    x + z = 2 * y
    Using base 3, if a number only contains 0 or 1 is good.
    If x, y, z are all good numbers, the above equality can't be satisfied,
    unless x = y = z.(It's easy to prove.)
*/

bool f(ll x){
    if(x % 3 != 0) return false;
    while(x > 0){
        if(x % 3 == 2)
            return false;
        x = x / 3;
    }
    return true;
}

int main(){
    ll n, m;
    cin >> n >> m;
    
    vector<ll> res;
    ll sum = 0, val = 0, count = 0;

    while(count < n){
        if(f(val)){
            res.push_back(val);
            sum += val;
            count ++;
        }
        val ++;    
    }

    ll tmp = (m - sum) % n;
    if(m < sum) tmp += n;
    sum += tmp;
    for(int i = 0; i < tmp; i ++)
        res[i] += 1;

    ll add = (m - sum) / n;

    for(auto i : res){
        cout << i + add << " ";
    }
}