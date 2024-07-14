#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int f(vector<int> &v, int index){
    int l = -1, r = v.size();
    while(l + 1 < r){
        int mid = (l + r) >> 1;
        if(v[mid] <= index) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    int n; cin >> n;
    vector<int> A(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i];
    int q; cin >> q;
    vector<vector<int>> query;
    for(int i = 0; i < q; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        query.push_back({a, b, c});
    } 

    unordered_map<int, vector<int>> um;
    for(int i = 1; i <= n; i ++){
        um[A[i]].push_back(i);
    }

    for(int i = 0; i < q; i ++){
        int l = query[i][0], r = query[i][1], x = query[i][2];
        int tmp = f(um[x], r) - f(um[x], l - 1);
        cout << tmp << endl; 
    }
}