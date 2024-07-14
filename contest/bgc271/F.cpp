#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int A[21][21];
map<int, int> lefttop[21], rightbotttom[21];

void DFSlefttop(int x, int y, int n, int val){
    val ^= A[x][y];
    if(x + y == n + 1){
        lefttop[x][val] ++;
        return ;
    }
    DFSlefttop(x + 1, y, n, val);
    DFSlefttop(x, y + 1, n, val);
}

void DFSrightbottom(int x, int y, int n, int val){
    val ^= A[x][y];
    if(x + y == n + 1){
        rightbotttom[x][val] ++;
        return ;
    }
    DFSrightbottom(x - 1, y, n, val);
    DFSrightbottom(x, y - 1, n, val);
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) cin >> A[i][j];
    }
    DFSlefttop(1, 1, n, 0);
    DFSrightbottom(n, n, n, 0);
    ll res = 0;
    for(int x = 1; x <= n; x ++){
        int y = n + 1 - x;
        for(auto &[val, count] : lefttop[x]){
            int tmp = val ^ A[x][y];
            auto it = rightbotttom[x].find(tmp);
            if(it != rightbotttom[x].end()){
                res += (ll) count * (ll) it->second;
            }
        }
    }
    cout << res << endl;
}