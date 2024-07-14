#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int h, w, start_x, start_y;

bool DFS(int x, int y, bool flag, vector<vector<int>> &c, vector<vector<int>> &dp){
    if(dp[x][y] == 1) return false;
    else dp[x][y] = 1;

    if(c[x][y] == 2) return false;
    // cout << x << " " << y << endl;

    vector<pair<int, int>> go = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(auto [a, b] : go){
        if(x == start_x + a and y == start_y + b and flag) return true;
    } 

    for(auto [a, b] : go){
        if(x + a <= h and x + a > 0 and y + b <= w and y + b > 0){
            if(DFS(x + a, y + b, true, c, dp) == true) return true;
        } 
    }
    return false;
}

int main(){
    cin >> h >> w;
    vector<vector<int>> c(h + 1, vector<int> (w + 1)), dp(h + 1, vector<int> (w + 1));
    for(int i = 1; i <= h; i ++){
        string s;
        cin >> s;
        for(int j = 1; j <= w; j ++){
            if(s[j - 1] == '.') c[i][j] = 1; // 1 -> road;
            else if(s[j - 1] == '#') c[i][j] = 2; // 2 -> obstacle
            else start_x = i, start_y = j, c[i][j] = 1;
        }
    }

    dp[start_x][start_y] = 1;
    vector<pair<int, int>> go = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(auto [a, b] : go){
        if(start_x + a <= h and start_x + a > 0 and start_y + b <= w and start_y + b > 0){
            if(DFS(start_x + a, start_y + b, false, c, dp) == true){
                cout << "Yes" << endl;
                return 0;
            }
        } 
    }
    cout << "No" << endl;
}