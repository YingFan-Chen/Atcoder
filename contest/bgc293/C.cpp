#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int A[11][11];
int h, w, res = 0;

void DFS(int x, int y, unordered_set<int> &us){
    us.insert(A[x][y]);
    if(x == h and y == w){
        res ++;
    }else{
        if(x + 1 <= h){
            if(us.find(A[x + 1][y]) == us.end()){
                DFS(x + 1, y, us);
            }
        }
        if(y + 1 <= w){
            if(us.find(A[x][y + 1]) == us.end()){
                DFS(x, y + 1, us);
            }
        }
    }
    us.erase(A[x][y]);
}

int main(){
    cin >> h >> w;
    for(int i = 1; i <= h; i ++)
        for(int j = 1; j <= w; j ++) cin >> A[i][j];
    unordered_set<int> us;
    DFS(1, 1, us);
    cout << res << endl;
}