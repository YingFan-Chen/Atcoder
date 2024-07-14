#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int cross(pair<int, int> a, pair<int, int> b){
    return a.first * b.second - a.second * b.first;
}

int main(){
    vector<pair<int, int>> v;
    for(int i = 0; i < 4; i ++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    bool res = true;
    if(cross({v[0].first - v[3].first, v[0].second - v[3].second}, {v[1].first - v[0].first, v[1].second - v[0].second}) < 0) res = false;
    if(cross({v[1].first - v[0].first, v[1].second - v[0].second}, {v[2].first - v[1].first, v[2].second - v[1].second}) < 0) res = false;
    if(cross({v[2].first - v[1].first, v[2].second - v[1].second}, {v[3].first - v[2].first, v[3].second - v[2].second}) < 0) res = false;
    if(cross({v[3].first - v[2].first, v[3].second - v[2].second}, {v[0].first - v[3].first, v[0].second - v[3].second}) < 0) res = false;
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
}