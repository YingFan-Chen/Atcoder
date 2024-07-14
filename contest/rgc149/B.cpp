#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for(int i = 0; i < nums.size(); ++i){
        int l = 0, r = dp.size(), mid;
        while(l < r){
            mid = (l + r) / 2;
            if(dp[mid] >= nums[i]) r = mid;
            else l = mid + 1;
        }
        if(r == dp.size()) dp.push_back(nums[i]);
        else dp[r] = nums[i];
    }
    return dp.size();
}

int main(){
    int n; cin >> n;
    vector<int> A, B;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        B.push_back(x);
    }
    map<int, int> m;
    for(int i = 0; i < n; i ++){
        m[A[i]] = B[i];
    }
    vector<int> newB;
    for(auto i : m) newB.push_back(i.second);
    int res = lengthOfLIS(newB);
    cout << res + n << endl;
}