#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> A(n + 1);
    map<int, int> m;

    for(int i = 1; i <= n; i ++){
        cin >> A[i];
        m[A[i]] ++;    
    }

    int res = 0, count = n;
    while(count > 1){
        int maxi = m.rbegin()->first, mini = m.begin()->first;
        if(m.rbegin()->second == 1){
            m.erase(maxi);
        }
        if(maxi % mini != 0){
            m[maxi % mini] ++;
        }else{
            count --;
        }
        res ++;
    }
    cout << res << endl;
}