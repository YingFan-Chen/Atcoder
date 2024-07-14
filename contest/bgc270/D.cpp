#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A(k);
    for(int i = 0; i < k; i ++){
        cin >> A[i];
    }
    vector<int> x(n + 1), y(n + 1);    
    for(int i = 1; i <= n; i ++){
        int maxi1 = 0, maxi2 = 0;
        for(auto j : A){
            if(j <= i){
                maxi1 = max(maxi1, i - y[i - j]);
                maxi2 = max(maxi2, i - x[i - j]);
            }
        }
        x[i] = maxi1;
        y[i] = maxi2;
    }

    cout << x[n] << endl;
}