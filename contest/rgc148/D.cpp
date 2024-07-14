#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    map<int, int> ma;

    int mod;
    if(m % 2){
        mod = INT_MAX;
    }else{
        mod = m / 2;
    }

    for(int i = 0; i < 2 * n; i ++){
        int tmp;
        cin >> tmp;
        ma[tmp % mod] ++;
    }
    for(auto i : ma){
        if(i.second % 2 == 1){
            cout << "Alice" << endl;
            return 0;
        }
    }
    cout << "Bob" << endl;

}