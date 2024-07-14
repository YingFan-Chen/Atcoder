#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

struct d{
    ll v, l;
};

int main(){
    ll L, N1, N2;
    cin >> L >> N1 >> N2;
    
    vector<d> A(N1), B(N2);
    for(int i = 0; i < N1; i ++){
        cin >> A[i].v >> A[i].l;
    }
    for(int i = 0; i < N2; i ++){
        cin >> B[i].v >> B[i].l;
    }

    ll a = -1, b = -1, a_val = 0, b_val = 0;
    ll i = 0, j = 0;
    ll res = 0;
    while(i < N1 or j < N2){
        if(a < b){
            if(A[i].v == b_val){
                res += min(a + A[i].l, b) - a;
            }
            a += A[i].l;
            a_val = A[i].v;
            i ++;
        }else{
            if(B[j].v == a_val){
                res += min(b + B[j].l, a) - b;
            }
            b += B[j].l;
            b_val = B[j].v;
            j ++;
        }
    }
    cout << res << endl;
}