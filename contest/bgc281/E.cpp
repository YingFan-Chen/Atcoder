#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

void debug(multiset<ll> &s){
    for(auto i : s) cout << i << " ";
    cout << endl;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i];
    
    ll sum = 0;
    multiset<ll> s1, s2;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<ll> res(n - m + 2);

    for(int i = 1; i <= m; i ++){
        pq.push(A[i]);
    }
    for(int i = 1; i <= k; i ++){
        s1.insert(pq.top());
        sum += pq.top();
        pq.pop();
    }
    while(pq.size()){
        s2.insert(pq.top());
        pq.pop();
    }
    res[1] = sum;

    for(int i = 2; i <= n - m + 1; i ++){
        ll head = A[i - 1], end = A[i + m - 1];
        if(end > *s1.rbegin()){
            s2.insert(end);
        }else{
            s1.insert(end);
            sum += end;
        }
        if(head > *s1.rbegin()){
            s2.erase(s2.find(head));
        }else{
            s1.erase(s1.find(head));
            sum -= head;
        }

        while(s1.size() > k){
            ll tmp = *s1.rbegin();
            s2.insert(tmp);
            s1.erase(s1.find(tmp));
            sum -= tmp;
        }  
        while(s1.size() < k){
            ll tmp = *s2.begin();
            s1.insert(tmp);
            sum += tmp;
            s2.erase(s2.find(tmp));
        }
        res[i] = sum;
    }
    for(int i = 1; i <= n - m + 1; i ++) cout << res[i] << " ";
    cout << endl;
}