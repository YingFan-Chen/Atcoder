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
    multiset<int> s;

    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        s.insert(x);
    }

    int count = 1, have = 0, nohave = 0;
    while(have + nohave * 2 < s.size()){
        if(s.find(count) == s.end()){
           nohave ++;
           if(have + nohave * 2 > s.size()) break;
        }else{
            have ++;
        }
        count ++;
    }
    cout << count - 1 << endl;
}