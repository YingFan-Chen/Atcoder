#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;
 
/* If only 2 elementsm -> always cout << 1 << endl; */

int main(){
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i ++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    vector<int> tmp;
    for(int i = 1; i < v.size(); i ++){
        tmp.push_back(v[i] - v[i - 1]);
    }
    int g = tmp[0];
    for(int i = 1; i < tmp.size(); i ++){
        g = __gcd(g, tmp[i]);
    }
    if(g == 1) cout << 2 << endl;
    else cout << 1 << endl;
}