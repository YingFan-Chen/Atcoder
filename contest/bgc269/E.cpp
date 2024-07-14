#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n; cin >> n;
    int l = 0, r = n + 1;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        cout << "?" << " " << 1 << " " << mid << " " << 1 << " " << n << endl;
        int t; cin >> t;
        if(t < mid) r = mid;
        else l = mid;
    }

    int x = r;
    l = 0; r = n + 1;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        cout << "?" << " " << 1 << " " << n << " " << 1 << " " << mid << endl;
        int t; cin >> t;
        if(t < mid) r = mid;
        else l = mid;
    }
    cout << "!" << " " << x << " " << r << endl;     
}