#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    int dif = 0, same = 0;
    for(int i = 0; i < n; i ++){
        if(s[i] == t[i]) same ++;
        else dif ++;
    }
    if(dif % 2 == 1) cout << -1 << endl;
    else{
        int l = dif / 2, r = dif / 2;
        for(int i = 0; i < n; i ++){
            if(s[i] == t[i]){
                cout << "0";
            }else{
                if(s[i] == '0'){
                    if(r > 0){
                        cout << "0";
                        r --;
                    }else{
                        cout << "1";
                        l --;
                    }
                }
                if(t[i] == '0'){
                    if(l > 0){
                        cout << "0";
                        l --;
                    }else{
                        cout << "1";
                        r --;
                    }
                }
            }
        }
        cout << endl;
    }
}