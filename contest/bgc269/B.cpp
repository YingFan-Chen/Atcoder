#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    vector<string> s(10);
    for(int i = 0; i < 10; i ++) cin >> s[i];
    int a = 0, b = 0, c = 0, d = 0;
    bool first = false;
    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j ++){
            if(s[i][j] == '#'){
                if(first == false) a = i, b = j, first = true;
                c = i; d = j;
            }
        }
    }
    cout << a + 1 << " " << c + 1 << endl;
    cout << b + 1 << " " << d + 1 << endl;
}