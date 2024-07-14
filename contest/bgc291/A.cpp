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
    for(int i = 0; i < s.size(); i ++){
        if(s[i] >= 'a' and s[i] <= 'z') continue;
        else{
            cout << i + 1 << endl;
            return 0;
        }
    }
}