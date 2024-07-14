#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

constexpr ll mod = 998244353;

int main(){
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i] >> B[i];
    vector<ll> flip(n + 1, 0), nflip(n + 1, 0);
    flip[1] = 1;
    nflip[1] = 1;
    for(int i = 2; i <= n; i ++){
        if(A[i] != A[i - 1]) flip[i] = (flip[i] + flip[i - 1]) % mod;
        if(A[i] != B[i - 1]) flip[i] = (flip[i] + nflip[i - 1]) % mod;
        if(B[i] != A[i - 1]) nflip[i] = (nflip[i] + flip[i - 1]) % mod;
        if(B[i] != B[i - 1]) nflip[i] = (nflip[i] + nflip[i - 1]) % mod; 
    }
    cout << (flip[n] + nflip[n]) % mod << endl;
}