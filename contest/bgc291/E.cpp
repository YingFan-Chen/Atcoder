#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

constexpr int C = 200005;

vector<int> out[C];
int inCount[C];


int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        int x, y;
        cin >> x >> y;
        // x < y
        out[x].push_back(y);
        inCount[y] ++;
    }

    vector<int> res(n + 1);
    vector<int> zero;
    for(int i = 1; i <= n; i ++){
        if(inCount[i] == 0) zero.push_back(i);
    }

    for(int i = 1; i <= n; i ++){
        if(zero.size() != 1){
            cout << "No" << endl;
            return 0;
        }

        int index = zero[0];
        zero.clear();
        res[index] = i;
        for(auto t : out[index]){
            inCount[t] --;
            if(inCount[t] == 0) zero.push_back(t);
        }
    }

    cout << "Yes" << endl;
    for(int i = 1; i <= n; i ++) cout << res[i] << " ";
    cout << endl;
}