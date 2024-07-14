#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int x; cin >> x;
    vector<char> map = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string res;
    if(x < 16){
        res += '0';
        res += map[x];
    }else{
        int tmp = x / 16;
        x %= 16;
        res += map[tmp];
        res += map[x];
    }
    cout << res << endl;
}