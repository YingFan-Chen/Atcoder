#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n + 1);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 1; i <= n; i ++){
        cin >> A[i];
        pq.push(A[i]);
    }

    ll remain = n, round = 0;
    while(pq.size() and (pq.top() - round) * remain <= k){
        ll tmp = pq.top() - round;
        pq.pop();
        round += tmp;
        k -= tmp * remain;
        remain --;
    }
    if(remain == 0){
        for(int i = 1; i <= n; i ++) cout << 0 << " ";
        cout << endl;
        return 0;
    }

    ll r = k % remain;
    round += (k - r) / remain;
    for(int i = 1; i <= n; i ++){
        A[i] = max(A[i] - round, (ll) 0);
    }
    for(int i = 1; i <= n; i ++){
        if(r == 0) break;
        if(A[i] > 0){
            A[i] --;
            r --;
        }
    }
    for(int i = 1; i <= n; i ++) cout << A[i] << " ";
    cout << endl;
}