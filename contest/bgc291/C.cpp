#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;

    set<pair<int, int>> visit;
    int x = 0, y = 0;
    visit.insert({x, y});
    for(int i = 0; i < n; i ++){
        if(s[i] == 'R'){
            x += 1;
        }else if(s[i] == 'L'){
            x -= 1;
        }else if(s[i] == 'U'){
            y += 1;
        }else{
            y -= 1;
        }

        if(visit.find({x, y}) != visit.end()){
            cout << "Yes" << endl;
            return 0;
        }
        visit.insert({x, y});
    }
    cout << "No" << endl;
}