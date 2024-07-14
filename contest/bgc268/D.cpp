#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;
int n, m;
set<string> s;
set<string> t;

string DFS(string &x, set<string> &remain, int count){
    vector<string> r;
    for(auto &i : remain) r.push_back(i);

    if(r.size() == 1){
        string tmp = x + r[0];
        if(tmp.size() <= 16 and tmp.size() >= 3){
            if(t.find(tmp) == t.end()) return tmp;
        }
        return "";
    }

    for(auto &i : r){
        string tmp = x + i;
        remain.erase(i);
        for(int j = 0; j <= count; j ++){
            tmp += "_";
            string k = DFS(tmp, remain, count - j);
            if(k != "") return k;
        }
        remain.insert(i); 
    }
    return "";
}

int main(){
    cin >> n >> m;
    int count = n - 1;
    for(int i = 0; i < n; i ++){
        string tmp;
        cin >> tmp;
        s.insert(tmp);
        count += tmp.size();
    }
    for(int i = 0; i < m; i ++){
        string tmp;
        cin >> tmp;
        t.insert(tmp);
    }
    string start = "";
    string res = DFS(start, s, 16 - count);
    if(res == "") cout << -1 << endl;
    else cout << res << endl;
}