#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a = 0; a < t; a ++){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int left = -1, right = -1;
        for(int i = 0; i < n; i ++){
            if(s[i] == '1'){
                left = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i --){
            if(s[i] == '1'){
                right = i;
                break;
            }
        }

        if(left == -1){
            int count = 0, num = 0;
            for(int i = 0; i < n; i ++){
                if(s[i] == '?'){
                    count ++;
                    if(count > k){
                        num = 2;
                        break;
                    }
                }else{
                    if(count == k){
                        num ++;
                    }
                    count = 0;
                }
            }
            if(count == k) num ++;
            if(num == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            for(int i = left; i <= right; i ++){
                if(s[i] == '1'){
                    k --;
                }else if(s[i] == '?'){
                    k --;
                }else{
                    k = -1;
                    break;
                }
            }
            if(k < 0){
                cout << "No" << endl;
            }else if(k == 0){
                cout << "Yes" << endl;
            }else{
                int l = 0, r = 0;
                for(int i = left - 1; i >= 0; i --){
                    if(s[i] == '?') l ++;
                    else break;
                }
                for(int i = right + 1; i < n; i ++){
                    if(s[i] == '?') r ++;
                    else break;
                }
                if(l + r < k){
                    cout << "No" << endl;
                }else if(l + r == k){
                    cout << "Yes" << endl;
                }else{
                    if(l == 0 or r == 0){
                        cout << "Yes" << endl;
                    }else{
                        cout << "No" << endl;
                    }
                }
            }
        }
    }
}