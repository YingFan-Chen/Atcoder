#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    set<int> s;
    for(int i = 0; i < 5; i ++){
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() << endl;
}