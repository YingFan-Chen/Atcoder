#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h), t(h);
    for(int i = 0; i < h; i ++) cin >> s[i];
    for(int i = 0; i < h; i ++) cin >> t[i];

    vector<string> S(w), T(w);
    for(int i = 0; i < w; i ++){
        for(int j = 0; j < h; j ++){
            if(s[j][i] == '#') S[i] += '#';
            else S[i] += '.';  
            
            if(t[j][i] == '#') T[i] += '#';
            else T[i] += '.';
        }
    }
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());
    for(int i = 0; i < w; i ++){
        if(S[i] != T[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl; 
}