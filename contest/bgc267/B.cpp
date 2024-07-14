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
    if(s[0] == '1'){
        cout << "No" << endl;
        return 0;
    }

    vector<int> stand(7);
    for(int i = 0; i < 10; i ++){
        if(s[i] != '0'){
            if(i == 0) stand[3] ++;
            if(i == 1) stand[2] ++;
            if(i == 2) stand[4] ++;
            if(i == 3) stand[1] ++;
            if(i == 4) stand[3] ++;
            if(i == 5) stand[5] ++;
            if(i == 6) stand[0] ++;
            if(i == 7) stand[2] ++;
            if(i == 8) stand[4] ++;
            if(i == 9) stand[6] ++;
        }
    }
    for(int i = 1; i < 6; i ++){
        if(stand[i] == 0){
            bool flag1 = false, flag2 = false;
            for(int j = i - 1; j >= 0; j --){
                if(stand[j] > 0){
                    flag1 = true;
                    break;
                }
            }
            for(int j = i + 1; j < 7; j ++){
                if(stand[j] > 0){
                    flag2 = true;
                    break;
                }
            }
            if(flag1 and flag2){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}