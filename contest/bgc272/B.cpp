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
    vector<vector<int>> p(m + 1);
    for(int i = 1; i <= m; i ++){
        int k; cin >> k;
        for(int j = 0; j < k; j ++){
            int tmp; cin >> tmp;
            p[i].push_back(tmp);
        }
    }
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= m; i ++){
        for(int j = 0; j < p[i].size(); j ++){
            for(int k = j + 1; k < p[i].size(); k ++){
                dp[p[i][j]][p[i][k]] ++;
                dp[p[i][k]][p[i][j]] ++;
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i != j and dp[i][j] == 0){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}