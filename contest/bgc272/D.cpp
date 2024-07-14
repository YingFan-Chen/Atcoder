#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;
 
int dp[401][401], flag[401][401];
struct grid{
    int x, y, count;
    grid(int x, int y, int count){
        this->x = x;
        this->y = y;
        this->count = count;
    }
};
 
int main(){
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> um;
    for(int i = 0; i <= n; i ++){
        for(int j = i; j <= n; j ++){
            int tmp = i * i + j * j;
            um[tmp].push_back({i, j});
        }
    }
 
    queue<grid> q;
    q.push(grid {1, 1, 1});
    flag[1][1] = 1;
    while(q.size()){
        int x = q.front().x, y = q.front().y, count = q.front().count;
        q.pop();
        dp[x][y] = count;
        for(auto &[i, j] : um[m]){
            if(x - i > 0 and  y - j > 0 and flag[x - i][y - j] == 0) q.push(grid {x - i, y - j, count + 1}), flag[x - i][y - j] = 1;
            if(x + i <= n and y + j <= n and flag[x + i][y + j] == 0) q.push(grid {x + i, y + j, count + 1}), flag[x + i][y + j] = 1;
            if(x - i > 0 and  y + j <= n and flag[x - i][y + j] == 0) q.push(grid {x - i, y + j, count + 1}), flag[x - i][y + j] = 1;
            if(x + i <= n and  y - j > 0 and flag[x + i][y - j] == 0) q.push(grid {x + i, y - j, count + 1}), flag[x + i][y - j] = 1;
            if(x - j > 0 and  y - i > 0 and flag[x - j][y - i] == 0) q.push(grid {x - j, y - i, count + 1}), flag[x - j][y - i] = 1;
            if(x + j <= n and y + i <= n and flag[x + j][y + i] == 0) q.push(grid {x + j, y + i, count + 1}), flag[x + j][y + i] = 1;
            if(x - j > 0 and  y + i <= n and flag[x - j][y + i] == 0) q.push(grid {x - j, y + i, count + 1}), flag[x - j][y + i] = 1;
            if(x + j <= n and  y - i > 0 and flag[x + j][y - i] == 0) q.push(grid {x + j, y - i, count + 1}), flag[x + j][y - i] = 1;   
        }
    }
 
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cout << dp[i][j] - 1 << " ";
        }
        cout << endl;
    }
}