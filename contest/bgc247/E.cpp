#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> A(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i];

    ll res = 0;
    vector<int> Max(n + 1), Min(n + 1), Bad(n + 1);
    int maxi = INT_MAX, mini = INT_MAX, bad = INT_MAX;
    for(int i = n; i > 0; i --){
        if(A[i] == x) maxi = i;
        if(A[i] == y) mini = i;
        if(A[i] > x or A[i] < y) bad = i;
        Max[i] = maxi;
        Min[i] = mini;
        Bad[i] = bad;
    }

    for(int i = 1; i <= n; i ++){
        ll tmp = min(Bad[i], n + 1) - max(Max[i], Min[i]);
        if(tmp > 0) res += tmp;
    }
    cout << res << endl;
}