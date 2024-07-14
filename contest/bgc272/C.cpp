#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> odd, even;
    for(int i = 0; i < n; i ++){
        int tmp; cin >> tmp;
        if(tmp % 2){
            odd.push_back(tmp);
        }else{
            even.push_back(tmp);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int res = -1;
    if(odd.size() >= 2){
        int n = odd.size();
        res = max(res, odd[n - 1] + odd[n - 2]);
    }
    if(even.size() >= 2){
        int n = even.size();
        res = max(res, even[n - 1] + even[n - 2]);
    }
    cout << res << endl;
}