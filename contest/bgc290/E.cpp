#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll solve(int n, vector<int> &pos){
    ll res = 0;
    int l = 0, r = pos.size() - 1;
    while(l < r){
        int leftLen = pos[l], rightLen = n - pos[r] + 1;
        if(leftLen <= rightLen){
            res += (ll) leftLen * (r - l);
            l ++;
        }else{
            res += (ll) rightLen * (r - l);
            r --;
        }
    }
    return res;
}


int main(){
    int n; cin >> n;
    vector<int> A(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i];

    ll totalConnection = 0;
    for(int i = 2; i <= n; i ++){
        totalConnection += (ll) (n - i + 1) * (i / 2);
    }

    unordered_map<int, vector<int>> posOfSameNum;
    for(int i = 1; i <= n; i ++){
        posOfSameNum[A[i]].push_back(i);
    }
    for(auto &[_, pos] : posOfSameNum){
        totalConnection -= solve(n, pos);
    }
    cout << totalConnection << endl;

}