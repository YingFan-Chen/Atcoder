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
    string sample = "atcoder";
    ll count = 0;
    for(int i = 0; i < 7; i ++){
        for(int j = 0; j < 7; j ++){
            if(sample[i] == s[j]){
                break;
            }
            int flag = 1;
            for(int k = 0; k < i; k ++){
                if(sample[k] == s[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag) count ++;
        }
    }
    cout << count << endl;
}