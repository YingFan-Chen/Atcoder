#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

/*
    Sort cmp can't use <= or >= 
*/

#define kN 200005
ll sum[kN], X[kN], score[kN];

bool cmp(int a, int b){
    return X[a] * sum[b] > X[b] * sum[a]; 
}

int main(){
    int n; cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i ++) cin >> s[i];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < s[i].size(); j ++){
            if(s[i][j] == 'X') X[i] ++;
            else{
                sum[i] += s[i][j] - '0';
                score[i] += (s[i][j] - '0') * X[i];
            }
        }
    }

    vector<int> res;
    for(int i = 0; i < n; i ++) res.push_back(i);
    sort(res.begin(), res.begin() + n, cmp);

    ll ans = 0, c = 0;
    for(auto i : res){
        ans += score[i];
        ans += sum[i] * c;
        c += X[i];
    }
    cout << ans << endl;
}