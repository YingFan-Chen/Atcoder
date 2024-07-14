#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, l;
    cin >> n >> l;  
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];

    int t = 0;
    for(auto i : a){
        if(t + i < l){
            t += i + 1;
        }else if(t + i == l){
            t += i;
        }else{
            if(i != 1){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}