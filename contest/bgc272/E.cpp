#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

struct Element{
    int val, index;
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<Element> v;
    for(int i = 1; i <= n; i ++){
        int A;
        cin >> A;
        v.push_back(Element{A, i});
    }

    vector<vector<Element>> um(n + 1);
    for(int i = 0; i < n; i ++){
        // a + x*b >= 0     x <= -a / b
        int tmp;
        if(v[i].val >= 0){
            tmp = 0;
        }else{
            tmp = ceil(- v[i].val / v[i].index);
        }
        um[tmp].push_back(v[i]);
    }
    unordered_set<Element*> im;
    for(auto &i : um[0]) im.insert(&i);
    for(int i = 1; i <= m; i ++){
        for(auto j : im){
            j->val += j->index;
            if(j->val > n) im.erase(j);
        }
        for(auto &j : um[i]) im.insert(&j);
        vector<int> count(n + 1);
        for(auto j : im){
            count[j->val] ++;
        }
        for(int j = 0; j <= n; j ++){
            if(count[j] == 0){
                cout << j << endl;
                break;
            }
        }
    }
}