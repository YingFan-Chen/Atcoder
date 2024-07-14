#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

/*
    Compute the cost to escape from the loop(dice with 0)
*/

static constexpr ll mod = 998244353;

/*
struct Seg_Tree{
    vector<ll> v, tag;
    Seg_Tree(int n){    
        v.resize(n << 2);
        tag.resize(n << 2);
    }

    void pull(int index){
        v[index] = (v[index << 1] + v[index << 1 + 1]) % mod;
    }
    void push(int index, int l, int r){
        int mid = (l + r) >> 1;
        v[index << 1] = (v[index << 1] + (mid - l + 1) * tag[index]) % mod;
        tag[index << 1] = (tag[index << 1] + tag[index]) % mod;
        v[index << 1 + 1] = (v[index << 1 + 1] + (r - mid) * tag[index]) % mod;
        tag[index << 1 + 1] = (tag[index << 1 + 1] + tag[index]) % mod;
        tag[index] = 0;
    }
    void update(int index, int l, int r, int tl, int tr, ll val){
        if(tl <= l and r <= tr){
            v[index] = (v[index] + (r - l + 1) * val) % mod;
            tag[index] = (tag[index] + val) % mod;
        }else{
            push(index, l, r);
            int mid = (l + r) >> 1;
            if(tl <= mid){
                update(index << 1, l, mid, tl, tr, val);
            }
            if(tr > mid){
                update(index << 1 + 1, mid + 1, r, tl, tr, val);
            }
            pull(index);
        }
    }
    ll query(int index, int l, int r, int tl, int tr){
        if(tl <= l and r <= tr){
            return v[index];
        }else{
            ll res = 0;
            push(index, l, r);
            int mid = (l + r) >> 1;
            if(tl <= mid){ 
                res = (res + query(index << 1, l, mid, tl, tr)) % mod;
            }
            if(tr > mid){
                res = (res + query(index << 1 + 1, mid + 1, r, tl, tr)) % mod;
            }
            return res;
        }
    }
};
*/

ll Pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) 
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 1; i < n; i ++)
        cin >> A[i];

    vector<ll> dp(n + 5);
    for(int i = n - 1; i > 0; i --){
        ll exp = (dp[i + 1] - dp[i + A[i] + 1] + A[i] + 1) % mod;
        exp = (exp * Pow(A[i], mod - 2)) % mod;
        dp[i] = exp + dp[i + 1];
    }

    cout << dp[1] - dp[2] << endl;
}