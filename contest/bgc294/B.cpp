#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    for(int i = 1; i <= h; i ++){
        vector<int> t(w);
        for(int j = 0; j < w; j ++) cin >> t[j];
        for(int j = 0; j < w; j ++){
            if(t[j] == 0) cout << ".";
            else cout << (char) ('A' + t[j] - 1);
        }
        cout << endl;
    }
}