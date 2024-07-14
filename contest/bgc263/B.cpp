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
    vector<int> p(n + 1);
    for(int i = 2; i <= n; i ++){
        cin >> p[i];
    }

    int count = 0;
    while(n > 1){
        count ++;
        n = p[n];
    }
    cout << count << endl;
}