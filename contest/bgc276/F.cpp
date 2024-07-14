#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

const ll mod = 998244353;

#ifndef _BINARY_INDEX_TREE
#define _BINARY_INDEX_TREE
class binary_index_tree{
        ll size;
        std::vector<ll> v;
    public:
        binary_index_tree(ll n) : size(n) {
            v.assign(n + 1, 0);
        }
        void update(ll index, ll x){
            while(index <= size){
                v[index] += x;
                index += index & (-index);
            }
            return ;
        }
        ll query(ll index){
            ll res = 0;
            while(index){
                res += v[index];
                index -= index & (-index);
            }
            return res;
        }
};
#endif

int main(){
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> A[i];
    }
    binary_index_tree num(1E6), sum(1E6);
    for(int i = 1; i <= n; i ++){
        
    }
}