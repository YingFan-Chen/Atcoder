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
    if(s == "Monday") cout << 5 << endl;
    else if(s == "Tuesday") cout << 4 << endl;
    else if(s == "Wednesday") cout << 3 << endl;
    else if(s == "Thursday") cout << 2 << endl;
    else if(s == "Friday") cout << 1 << endl;
    else if(s == "Saturday") cout << 0 << endl;
    else cout << 6 << endl;
}