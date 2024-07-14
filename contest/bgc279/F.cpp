#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

struct disjoint_set{
    vector<int> v;
    disjoint_set(int n){
        v.resize(n + 1, - 1);
    }
    int query(int x){
        if(v[x] < 0) return x;
        else return v[x] = query(v[x]);
    }

    void merge(int x, int y){
        if(query(x) == query(y)) return;
        v[query(x)] += v[query(y)];
        v[query(y)] = query(x);      
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> query(q);
    for(int i = 0; i < q; i ++){
        int tmp, x, y;
        cin >> tmp;
        query[i].push_back(tmp);
        if(tmp == 1){
            cin >> x >> y;
            query[i].push_back(x);
            query[i].push_back(y);
        }else{
            cin >> x;
            query[i].push_back(x);
        }
    }

    int count = n;
    disjoint_set ds(1e6);
    vector<int> box(1e6), pos(1e6);
    for(int i = 1; i <= n; i ++) box[i] = i, pos[i] = i;

    for(auto &v : query){
        if(v[0] == 1){
            int x = v[1], y = v[2];
            if(box[y] != -1){
                if(box[x] == -1){
                    box[x] = box[y];
                    pos[box[x]] = x; 
                    box[y] = -1;
                }else{
                    ds.merge(box[x], box[y]);
                    box[y] = -1;
                }
            } 
        }else if(v[0] == 2){
            int x = v[1];
            count ++;
            if(box[x] == -1){
                box[x] = count;
                pos[box[x]] = x;
            }else{
                ds.merge(box[x], count);
            }
        }else{
            int x = v[1], res = pos[ds.query(x)];
            cout << res << endl;
        }
    }
}