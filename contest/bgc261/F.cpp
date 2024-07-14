#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "C:\Users\josep\code\c++\lib\debug"
#endif
using namespace std;

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
    vector<int> C(n + 1), X(n + 1);
    for(int i = 1; i <= n; i ++) cin >> C[i];
    for(int i = 1; i <= n; i ++) cin >> X[i];
    
    unordered_map<int, vector<pair<int, int>>> um;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for(int i = 1; i <= n; i ++){
        if(um.find(C[i]) == um.end()) um[C[i]].push_back({0, 0});
        um[C[i]].push_back({X[i], i});
        pq.push({X[i], i});
    }

    vector<int> counts(n + 1);
    for(auto &i : um){
        binary_index_tree BIT(i.second.size() + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tmp;
        for(int j = 1; j < i.second.size(); j ++) tmp.push({i.second[j].first, j});
        while(tmp.size()){
            auto [val, index] = tmp.top();
            tmp.pop();
            counts[i.second[index].second] -= BIT.query(i.second.size() + 1) - BIT.query(index); 
            BIT.update(index, 1);
        }
    }

    binary_index_tree BIT(n + 1);
    while(pq.size()){
        auto [val, index] = pq.top();
        pq.pop();
        counts[index] += BIT.query(n + 1) - BIT.query(index);
        BIT.update(index, 1); 
    }

    ll res = 0;
    for(auto i : counts) res += i;
    cout << res << endl;
}