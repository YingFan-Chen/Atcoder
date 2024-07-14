#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll GCD(ll a, ll b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    else return GCD(b, a % b); 
}

int main(){
    ll A, B;
    cin >> A >> B;
}