#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

void f(string &s, vector<string> &v, int l, int r){
    int n = s.size();
    string res = s;
    for(int i = 0; i <= r - l; i ++){
        if(s[r - i] == 'd') res[l + i] = 'p';
        else res[l + i] = 'd';
    }
    v.push_back(res);
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = -1;
    for(int i = 0; i < n; i ++){
        if(s[i] == 'p'){
            l = i;
            break;
        }
    }
    if(l == -1){
        cout << s << endl;
        return 0;
    }
    
    vector<string> v;
    v.push_back(s);
    for(int i = l; i < n; i ++){
        f(s, v, l , i);
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
}