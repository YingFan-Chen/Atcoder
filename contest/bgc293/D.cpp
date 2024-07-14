#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

#ifndef _DISJOINT_SET
#define _DISJOINT_SET
class disjoint_set{
    public:
        std::vector<ll> v; 
        disjoint_set(ll n){
            v.assign(n, -1);
        }
        ll find(ll x){
            if(v[x] < 0) return x;
            else{
                ll root = find(v[x]);
                v[x] = root;
                return root;
            }
        }
        void merge(ll x, ll y){
            ll root1 = find(x), root2 = find(y);
            if(root1 != root2){
                if(v[root1] < v[root2]){
                    v[root1] += v[root2];
                    v[root2] = root1;
                }else{
                    v[root2] += v[root1];
                    v[root1] = root2;
                }
            }
            return ;
        }
        /* merge method will merge according to size of two sets, and deterministic_merge method will merge set y to set x. */
        void deterministic_merge(ll x, ll y){
            ll root1 = find(x), root2 = find(y);
            if(root1 != root2){
                v[root1] += v[root2];
                v[root2] = root1;
            }
            return ;
        }
        ll size(ll x){
            return - v[find(x)];
        }
};
#endif

int main(){
    int n, m;
    cin >> n >> m;
    disjoint_set ds(n + 1);
    vector<int> cycle(n + 1);
    for(int i = 1; i <= m; i ++){
        int A, C;
        char B, D;
        cin >> A >> B >> C >> D;
        if(A > C) swap(A, C);
        if(ds.find(A) == ds.find(C)){
            cycle[ds.find(A)] = 1;
        }else{
            ds.deterministic_merge(A, C);
        }
    }
    int x = 0, y = 0;
    for(int i = 1; i <= n; i ++){
        if(ds.v[i] < 0){
            if(cycle[i] == 1) x ++;
            else y ++;
        }
    }
    cout << x << " " << y << endl;
}