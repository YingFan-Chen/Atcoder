#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> tmp, res;
    
    for(int i = 0; i < n; i ++){
        tmp.clear();
        if(i == 0){
            for(int j = 1; j <= m; j ++){
                res.push_back({j});
            }
        }else{
            for(auto &j : res){
                vector<int> cp = j;
                int final = cp[i - 1];
                for(int k = final + 1; k <= m; k ++){
                    cp.push_back(k);
                    tmp.push_back(cp);
                    cp.pop_back();
                }
            }
            res = tmp;
        }
    }
    for(auto &i : res){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}