#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int q;
    cin >> q;
    vector<string> s(q + 1);
    vector<int> v(q + 1);
    unordered_map<int, int> count;

    for(int i = 1; i <= q; i ++){
        cin >> s[i];
        if(s[i] != "DELETE") cin >> v[i];
    }

    int pre = 0, tmp = 0;
    for(int i = q; i > 0; i --){
        if(s[i] == "DELETE"){
            tmp ++;
        }
        if(s[i] == "LOAD"){
            count[v[i]] = max(count[v[i]], tmp + count[pre]);
            pre = v[i];
            tmp = 0;
        }
    }

    unordered_map<int, vector<int>> um;
    vector<int> res;
    for(int i = 1; i <= q; i ++){
        if(s[i] == "ADD"){
            res.push_back(v[i]);
        }
        if(s[i] == "DELETE"){
            if(res.size()) res.pop_back();
        }
        if(s[i] == "SAVE"){
            int t = count[v[i]] + 1;
            um[v[i]].clear();
            int index = res.size() - t;
            if(index < 0) index = 0;
            for(; index < res.size(); index ++) um[v[i]].push_back(res[index]);
        }
        if(s[i] == "LOAD"){
            res = um[v[i]];
        }
        if(res.size() == 0) cout << -1 << " ";
        else cout << *res.rbegin() << " ";
    }
    cout << endl;
} 