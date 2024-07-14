#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

string s;

struct Segment_Tree1{
    vector<int> v;
    Segment_Tree1(int n){
        v.resize(n << 2);
    }
    void pull(int index){
        v[index] = v[index << 1] + v[index << 1 | 1]; 
    }
    void update(int index, int x, int l, int r, int val){
        if(l == r){
            v[index] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(x <= mid) update(index << 1, x, l, mid, val);
        else update(index << 1 | 1, x, mid + 1, r, val);
        pull(index);
    }
    int query(int index, int tl, int tr, int l, int r){
        if(tl <= l and r <= tr) return v[index];
        int mid = (l + r) >> 1, res = 0;
        if(tl <= mid) res += query(index << 1, tl, tr, l, mid);
        if(tr > mid) res += query(index << 1 | 1, tl, tr, mid + 1, r);
        return res;
    }
};

/* Haven't find the bug!
struct Segment_Tree2{
    vector<bool> v;
    Segment_Tree2(int n){
        v.resize(n << 2);
    }
    void update(int index, int x, int l, int r){
        if(l == r){
            v[index] = true;
            return;
        }
        int mid = (l + r) >> 1;
        if(x <= mid) update(index << 1, x, l, mid);
        else update(index << 1 | 1, x, mid + 1, r);
        v[index] = v[index << 1] & v[index << 1 | 1] & (s[mid] <= s[mid + 1]);
    }
    bool query(int index, int tl, int tr, int l, int r){
        if(tl <= l and r <= tr) return v[index];
        int mid = (l + r) >> 1;
        bool res = (s[mid] <= s[mid + 1]);
        if(tl <= mid) res &= query(index << 1, tl, tr, l, mid);
        if(tr > mid) res &= query(index << 1 | 1, tl, tr, mid + 1, r);
        return res;
    }
}; 
*/

int main(){
    int n, q;
    cin >> n >> s >> q;
    vector<Segment_Tree1> tree(26, Segment_Tree1(n));
    vector<int> total(26);
    set<int> cont;

    for(int i = 0; i < n; i ++){
        char c = s[i] - 'a';
        tree[c].update(1, i, 0, n - 1, 1);
        total[c] ++;
    }

    for(int i = 0; i < n - 1; i ++){
        if(s[i] > s[i + 1]) cont.insert(i); 
    }

    for(int i = 0; i < q; i ++){
        int a;
        cin >> a;
        if(a == 1){
            int b;
            char c, tmp;
            cin >> b >> c;
            
            b --;

            tmp = s[b] - 'a';
            tree[tmp].update(1, b, 0, n - 1, 0);
            total[tmp] --;

            s[b] = c;

            tmp = c - 'a';
            tree[tmp].update(1, b, 0, n - 1, 1);
            total[tmp] ++;
            if(b != 0){
                if(s[b - 1] > s[b]){
                    cont.insert(b - 1);
                }else{
                    if(cont.find(b - 1) != cont.end()) cont.erase(b - 1);
                }
            }
            
            if(b != n - 1){
                if(s[b] > s[b + 1]){
                    cont.insert(b);
                }else{
                    if(cont.find(b) != cont.end()) cont.erase(b);
                }
            }

        }else{
            int b, c;
            cin >> b >> c;
            b --; c --;
            bool res = (cont.lower_bound(b) == cont.lower_bound(c));
            
            vector<int> tmp(26);
            for(int j = 0; j < 26; j ++){
                tmp[j] = tree[j].query(1, b, c, 0, n - 1);
            }

            int l, r;
            for(int j = 0; j < 26; j ++){
                if(tmp[j] != 0){
                    l = j + 1;
                    break;
                }
            }
            for(int j = 25; j >= 0; j --){
                if(tmp[j] != 0){
                    r = j - 1;
                    break;
                }
            }

            for(int j = l; j <= r; j ++){
                res &= (tmp[j] == total[j]);
            }
            
            if(res == false) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }

}