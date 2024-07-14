#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int f(vector<ll> &v, int l, int r, int start, ll target){
    while(l + 1 < r){
        int mid = (l + r) >> 1;
        ll tmp;
        if(start == 0) tmp = v[mid - 1];
        else tmp = v[mid - 1] - v[start - 1];
        if(tmp <= target) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> A(n + 5);
    for(int i = 0; i < n; i ++){
        ll tmp;
        cin >> tmp;
        if(i != 0){
            A[i] += A[i - 1];
        }
        A[i] += tmp; 
    }
    for(int i = n; i < n + 5; i ++){
        A[i] = A[i - 1];
    }

    for(int i = 0; i + 3 <= n; i ++){
        int x = i;
        int y = f(A, x + 1, n + 1, x, p);
        ll tmp;
        if(x == 0) tmp = A[y - 1];
        else tmp = A[y - 1] - A[x - 1];
        if(tmp != p) continue;
        int z = f(A, y + 1, n + 1, y, q);
        if(A[z - 1] - A[y - 1] != q) continue;
        int w = f(A, z + 1, n + 1, z, r);
        if(A[w - 1] - A[z - 1] != r) continue;
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;

}