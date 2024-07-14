#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "C:\Users\josep\code\c++\lib\debug"
#endif
using namespace std;

bool f(int x, int *A, int a, int b, int n){
    ll add = 0, sub = 0;
    for(int i = 1; i <= n; i ++){
        if(A[i] > x){
            sub += (A[i] - x) / b;
        }else if(A[i] < x){
            add += (x - A[i] + a - 1) / a; 
        }  
    }
    if(sub >= add) return true;
    else return false;
}


int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int A[n + 1];
    for(int i = 1; i <= n; i ++) cin >> A[i];

    ll sum = 0;
    for(int i = 1; i <= n; i ++) sum += A[i];
    int l = 1, r = sum / n + 1;

    while(l + 1 < r){
        int mid = (l + r) >> 1;
        if(f(mid, A, a, b, n)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}