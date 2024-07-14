#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

ll powtwo[32], powthree[32];

void setup(){
    powtwo[0] = powthree[0] = 1;
    for(int i = 1; i < 32; i ++){
        powtwo[i] = powtwo[i - 1] * 2;
        powthree[i] = powthree[i - 1] * 3;
    }
}


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<int> two(n), three(n);
    setup();
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < 32; j ++){
            if(a[i] % powtwo[j] == 0) two[i] = j;
            if(a[i] % powthree[j] == 0) three[i] = j;
        }
        a[i] = a[i] / powtwo[two[i]] / powthree[three[i]];
    }
    for(int i = 1; i < n; i ++){
        if(a[i] != a[0]){
            cout << -1 << endl;
            return 0;
        }
    }

    int twomin = 32, threemin = 32;
    for(int i = 0; i < n; i ++) twomin = min(twomin, two[i]), threemin = min(threemin, three[i]);
    int res = 0;
    for(int i = 0; i < n; i ++){
        res += two[i] - twomin;
        res += three[i] - threemin;
    }
    cout << res << endl;
}