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
    vector<vector<char>> G(h + 1, vector<char> (w + 1));
    for(int i = 1; i <= h; i ++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j ++){
            G[i][j + 1] = s[j];
        }
    }

    set<pair<int, int>> s;
    s.insert({1, 1});
    pair<int, int> cur = {1, 1};

    while(true){
        auto [x, y] = cur;
        if(G[x][y] == 'U'){
            cur.first --;
        }else if(G[x][y] == 'D'){
            cur.first ++;
        }else if(G[x][y] == 'L'){
            cur.second --;
        }else{
            cur.second ++;
        }

        if(cur.first >= 1 and cur.first <= h and cur.second >= 1 and cur.second <= w){
            if(s.find(cur) == s.end()){
                s.insert(cur);
            }else{
                cout << -1 << endl;
                return 0;
            }
        }else{
            cout << x << " " << y << endl;
            return 0;
        }
    }
}