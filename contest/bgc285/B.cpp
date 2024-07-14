#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> res;
    for(int i = 1; i < n; i ++){
        int j = 0;
        for(; j + i < n; j ++){
            if(s[j] == s[j + i]) break;
        }
        res.push_back(j);
    }
    for(auto i : res){
        cout << i << endl;
    }
}