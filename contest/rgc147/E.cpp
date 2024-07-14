#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

void debug(string s, multiset<int> &m){
    cout << s << " ";
    for(auto i : m) cout << i << " ";
    cout << endl;
}
void debug(string s, multiset<pair<int, int>> &m){
    cout << s << " ";
    for(auto i : m) cout << "[" << i.first << ", " << i.second << "]" << " ";
    cout << endl;
}

struct sg{
    int n;
    vector<pair<int, int>> v;
    sg(int _n){
        n = _n;
        v.resize(n << 2);
    }
    void modify(int index, int l, int r, int target, int val){
        if(l == r) v[index] = {val, target};
        else{
            int mid = (l + r) >> 1;
            if(target <= mid){
                modify(index << 1, l, mid, target, val);
            }else{
                modify(index << 1 | 1, mid + 1, r, target, val);
            }
            if(v[index << 1].first <= v[index << 1 | 1].first) v[index] = v[index << 1];
            else v[index] = v[index << 1 | 1];
        }
    }
    pair<int, int> query(int index, int l, int r, int tl, int tr){
        if(l == tl && r == tr) return v[index];
        int mid = (l + r) >> 1;
        if(tr <= mid) 
            return query(index << 1, l, mid, tl, tr);
        else if(tl > mid) 
            return query(index << 1 | 1, mid + 1, r, tl, tr);
        else{
            auto a = query(index << 1, l, mid, tl, mid);
            auto b = query(index << 1 | 1, mid + 1, r, mid + 1, tr);
            if(a.first <= b.first) {
                return a;
            }else{
                return b;
            }
        }
    }
};

int main(){
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1);
    multiset<int> need, have; 
    int res = 0;
    vector<pair<int, int>> good;

    for(int i = 1; i <= n; i ++){
        cin >> A[i] >> B[i];
        if(A[i] < B[i]){
            need.insert(B[i]);
            have.insert(A[i]);
        }else{
            good.push_back({A[i], B[i]});
            res ++;
        }
    }
    sort(good.begin(), good.end());
    int k = res;
    sg ST(k);
    for(int i = 0; i < k; i ++){
        ST.modify(1, 0, k - 1, i, good[i].second);
    }

    while(need.size()){
        //debug("need", need);
        //debug("have", have);
        int tmp = *need.rbegin();
        auto it = have.lower_bound(tmp);
        if(it == have.end()){
            int l = -1, r = k;
            while(l + 1 < r){
                int mid = (l + r) >> 1;
                if(good[mid].first < tmp) l = mid;
                else r = mid;
            }
            if(r == k){
                cout << -1 << endl;
                return 0;
            }
            auto p = ST.query(1, 0, k - 1, r, k - 1);
            if(p.first == INT_MAX){
                cout << -1 << endl;
                return 0;
            }
            ST.modify(1, 0, k - 1, p.second, INT_MAX);
            need.insert(p.first);
            have.insert(good[r].first);
            res --;
        }else{
            need.erase(need.find(tmp));
            have.erase(it);
        }
    }
    cout << res << endl;
}