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
    vector<vector<int>> dp(h + 1, vector<int> (w + 1));
    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++){   
            char c;
            cin >> c;
            if(c == '#') dp[i][j] = 1;
        }
    }
    for(int j = 1; j <= w; j ++){
        int count = 0;
        for(int i = 1; i <= h; i ++){
            if(dp[i][j]) count ++;
        }
        cout << count << " ";
    }
    cout << endl;
}