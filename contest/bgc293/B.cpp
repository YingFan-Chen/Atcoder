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
    for(int i = 1; i <= n; i ++) cin >> A[i];

    for(int i = 1; i <= n; i ++){
        if(A[i] != 0){
            A[A[i]] = 0;
        }
    }
    
    int count = 0;
    for(int i = 1; i <= n; i ++) if(A[i] != 0) count ++;
    cout << count << endl;
    for(int i = 1; i <= n; i ++){
        if(A[i] != 0) cout << i << " ";
    }
    cout << endl;
}