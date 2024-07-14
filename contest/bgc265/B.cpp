#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> A(n);
    for(int i = 1; i < n; i ++) cin >> A[i];
    vector<ll> bonus(n);
    for(int i = 0; i < m; i ++){
        ll a, b;
        cin >> a >> b;
        bonus[a] = b;
    }

    for(int i = 1; i < n; i ++){
        t += bonus[i];
        if(t > A[i]){
            t -= A[i]; 
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}