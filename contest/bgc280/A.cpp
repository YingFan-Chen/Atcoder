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
    vector<string> g(h);
    for(int i = 0; i < h; i ++) cin >> g[i];
    int res = 0;
    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j ++)
            if(g[i][j] == '#') res ++;
    }
    cout << res << endl;
}