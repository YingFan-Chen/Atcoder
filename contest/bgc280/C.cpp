#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int res = t.size();
    for(int i = 0; i < s.size(); i ++){
        if(s[i] != t[i]){
            res = i + 1;
            break;
        } 
    }
    cout << res << endl;
}