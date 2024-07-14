#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

/* 
    if M > m, m <= Xi <= M is optimal.
*/

vector<pair<int, int>> p(300'000);

struct cmp1{
    bool operator()(int a, int b){
        return p[a].first <= p[b].first;
    }
};

struct cmp2{
    bool operator()(int a, int b){
        return p[a].second >= p[b].second;
    }
};

ll f(priority_queue<int, vector<int>, cmp1> &pq1, priority_queue<int, vector<int>, cmp2> &pq2, set<int> &s){
    int m, M;
    while(s.find(pq1.top()) == s.end()){
        if(pq1.empty()) return 0;
        pq1.pop();
    }
    while(pq2.size() and s.find(pq2.top()) == s.end()){
        if(pq1.empty()) return 0;
        pq2.pop();
    }
    M = pq1.top();
    m = pq2.top();
    //cout << M << " " << m << endl;
    if(p[M].first <= p[m].second) return 0;
    s.erase(M);
    s.erase(m);
    pq1.pop();
    pq2.pop();
    ll res = (s.size() + 1) * (p[M].first - p[m].second) + f(pq1, pq2, s);
    return res;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i ++){
        int l, r;
        cin >> l >> r;
        p[i] = {l, r};
    }
    priority_queue<int, vector<int>, cmp1> pq1;
    priority_queue<int, vector<int>, cmp2> pq2;
    set<int> s;
    for(int i = 0; i < n; i ++){
        pq1.push(i);
        pq2.push(i);
        s.insert(i);
    } 
    ll res = f(pq1, pq2, s);
    cout << res << endl;
}