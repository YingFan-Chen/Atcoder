#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    string s;
    cin >> s;
    int res = -1;
    for(int i = 1; i <= s.size(); i ++){
        if(s[i - 1] == 'a') res = i; 
    }
    cout << res << endl;
}