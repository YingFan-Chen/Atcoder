#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i += 2){
        swap(s[i], s[i + 1]);
    }
    cout << s << endl;
}