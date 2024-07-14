#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> A[i];
    }

    set<int> s;
    vector<int> v;
    for(int i = 1; i <= n; i ++){
        if(s.find(A[i]) == s.end()){
            v.push_back(A[i]);
            s.insert(A[i]);
        }
    }
    sort(v.begin(), v.end());

    vector<int> res(n);
    for(int i = 1; i <= n; i ++){
        int l = -1, r = v.size();
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(v[mid] > A[i]) r = mid;
            else l = mid;
        }
        int t = v.size() - r;
        res[t] ++;
    }
    for(int i = 0; i < n; i ++){
        cout << res[i] << endl;
    }
}