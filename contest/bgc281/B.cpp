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
    if(s.size() != 8){
        cout << "No" << endl;
    }else{
        if(s[0] < 'A' or s[0] > 'A' + 25){
            cout << "No" << endl;
        }else{
            if(s[7] < 'A' or s[7] > 'A' + 25){
                cout << "No" << endl;
            }else{
                string t = s.substr(1, 6);
                int num = stoi(t);
                if(num >= 100000 and num <= 999999) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }
    }
}