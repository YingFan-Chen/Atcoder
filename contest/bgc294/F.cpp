#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

double concentration(int a, int b){
    return (double) 100 * (double) a / double (a + b);
}


int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n), B(n), C(m), D(m);
    for(int i = 0; i < n; i ++) cin >> A[i] >> B[i];
    for(int i = 0; i < m; i ++) cin >> C[i] >> D[i];

    vector<pair<int, int>> s(m);
    for(int i = 0; i < m; i ++) s[i] = {C[i], D[i]};

    sort(s.begin(), s.end(), [] (const pair<int,int> &a, const pair<int,int> &b){
        (double) a.first / a.second < (double) b.first / b.second; 
    }); 

    vector<pair<int, int>> index(n);
    for(int i = 0; i < n; i ++) index[i] = {0, m};

    while(){
        double tmp = 0;
        for(int i = 0; i < n; i ++){
            if(index[i].first + 1 < index[i].second){
                int t = (index[i].first + index[i].second) / 2;
                tmp = concentration(A[i] + s[t].first, B[i] + s[t].second);
                break;
            }
        }
        vector<int> V(n);
        for(int i = 0; i < n; i ++){
            int l = index[i].first, r = index[i].second;
        }
    }

}