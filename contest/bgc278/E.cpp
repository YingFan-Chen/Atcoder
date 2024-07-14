#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<int>> res(H - h + 1, vector<int> (W - w + 1));
    vector<int> x_min(N + 1, -1), y_min(N + 1, -1), x_max(N + 1, -1), y_max(N + 1, -1);
    for(int i = 0; i < H; i ++){
        for(int j = 0; j < W; j ++){
            int tmp;
            cin >> tmp;

            if(x_min[tmp] == -1) x_min[tmp] = i;
            else x_min[tmp] = min(x_min[tmp], i);
            if(y_min[tmp] == -1) y_min[tmp] = j;
            else y_min[tmp] = min(y_min[tmp], j);
            x_max[tmp] = max(x_max[tmp], i);
            y_max[tmp] = max(y_max[tmp], j);
        }
    }
    for(int i = 0; i < H - h + 1; i ++){
        for(int j = 0; j < W - w + 1; j ++){
            for(int c = 1; c <= N; c ++){
                if(x_min[c] != -1){
                    if(x_min[c] >= i and x_max[c] < i + h and y_min[c] >= j and y_max[c] < j + w){
                        res[i][j] ++;
                    }
                }else res[i][j] ++;
            }
        }
    }
    for(int i = 0; i < H - h + 1; i ++){
        for(int j = 0; j < W - w + 1; j ++){
            cout << N - res[i][j] << " ";
        }
        cout << endl;
    }
}