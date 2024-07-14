#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    for(int i = 0; i < n; i ++){
        cin >> A[i];
    }

    vector<int> res(31, 0);
    for(int i = 31; i >= 1; i --){
        ll mod = pow(2, i), want = pow(2, i - 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < A.size(); i ++){
            ll tmp = A[i] % mod;
            if(tmp >= want){
                pq.push({0, i});
            }else{
                pq.push({want - tmp, i});
            }
        }
        
        ll count = 0, sum = 0;
        vector<ll> tmp;
        while(count < k or pq.top().first == 0){
            auto [add, index] = pq.top();
            pq.pop();
            if(add == 0){
                tmp.push_back(A[index]);
            }else{
                tmp.push_back(want);
            }
            sum += add;
            count ++;
        }

        //cout << sum << " " << m << endl;
        if(sum <= m){
            m -= sum;
            A = tmp;
            res[i - 1] = 1;
        }
    }

    ll ans = 0;
    for(int i = 0; i <= 31; i ++){
        if(res[i] == 1)
            ans += 1 << i;
    }
    
    cout << ans << endl;
}