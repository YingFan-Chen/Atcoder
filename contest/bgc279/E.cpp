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
    vector<int> a(m + 1);
    for(int i = 1; i <= m; i ++) cin >> a[i];
    
    vector<int> pos(m + 1);
    int now = 1;
    pos[0] = now;
    for(int i = 1; i <= m; i ++){
        if(a[i] == now) now = a[i] + 1;
        else if(a[i] + 1 == now) now = a[i];
        pos[i] = now;
    }

    vector<int> res(m + 1);
    vector<int> back(n + 1);
    for(int i = 1; i <= n; i ++) back[i] = i;
    for(int i = m; i > 0; i --){
        res[i] = back[pos[i - 1]];
        swap(back[a[i]], back[a[i] + 1]);
    }
    for(int i = 1; i <= m; i ++){
        cout << res[i] << endl;
    }
}