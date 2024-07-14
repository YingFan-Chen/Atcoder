#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    map<int, int> m;
    for(int i = 0; i < 5; i ++){
        int tmp;
        cin >> tmp;
        m[tmp] ++;
    }

    vector<int> tmp;
    for(auto i : m) tmp.push_back(i.second);
    sort(tmp.begin(), tmp.end());
    if(tmp[0] == 2 and tmp[1] == 3) cout << "Yes" << endl;
    else cout << "No" << endl;
}