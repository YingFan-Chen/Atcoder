#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){ 
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i ++) cin >> p[i];

    vector<int> res1, res2;
    int opCount;

    /* 
        No rotation
    */
    opCount = k;
    for(int i = 1; i <= n; i ++){
        while(res1.size()){
            int tmp = *res1.rbegin();
            if(tmp > p[i] and opCount > 0){
                res1.pop_back();
                opCount --;
            }else break;
        }
        res1.push_back(p[i]);
    }
    while(opCount > 0){
        res1.pop_back();
        opCount --;
    }

    /*
        With rotation
    */
    vector<int> p2;
    set<int> s;
    p2.push_back(p[1]);
    int r = n;
    opCount = k;
    for(int l = n; l > n - k; l --){
        int tmp = *p2.rbegin();
        if(p[l] < tmp){
            p2.push_back(p[l]);
            s.insert(p[l]);
            for(int i = l; i <= r; i ++){
                p.pop_back();
            }
            opCount -= r - l + 1;
            r = l - 1;
        }
    }
    reverse(p2.begin(), p2.end());
    p2.pop_back();
    for(int i = 1; i < p.size(); i ++) 
        p2.push_back(p[i]);

    for(int i = 0; i < p2.size(); i ++){
        while(res2.size()){
            int tmp = *res2.rbegin();
            if(opCount == 0 and s.find(tmp) == s.end()) break;
            if(tmp > p2[i]){
                res2.pop_back();
                if(s.find(tmp) == s.end())
                    opCount --;
            }else break;
        }
        res2.push_back(p2[i]);
    }
    
    /*
        compare res1, res2
    */
    int res = 0;
    for(int i = 0; i < min(res1.size(), res2.size()); i ++){
        if(res1[i] < res2[i]){
            res = 1;
            break;
        }else if(res1[i] > res2[i]){
            res = 2;
            break;
        }
    }
    if(res == 0){
        if(res1.size() >= res2.size()){
            res = 2;
        }else{
            res = 1;
        }
    }
    if(res == 1){
        for(auto i : res1) cout << i << " ";
    }else{
        for(auto i : res2) cout << i << " ";
    }
}