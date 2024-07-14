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
    if(s.size() > t.size()) cout << "No" << endl;
    else{
        for(int i = 0; i < s.size(); i ++){
            if(s[i] != t[i]){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
}