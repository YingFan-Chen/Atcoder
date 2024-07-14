#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> X(m + 1), Y(m + 1);
    for(int i = 1; i <= m; i ++) cin >> X[i] >> Y[i];

    vector<pair<ll, ll>> square;
    for(int i = 1; i <= m; i ++){
        square.push_back({X[i], Y[i]});
    }
    sort(square.begin(), square.end());
    
    if(square.size() == 0){
        if(n % 2 == 1){
            cout << "Takahashi" << endl;
        }else{
            cout << "Aoki" << endl;
        }
    }else{
        ll dif = 0, same = 0;
        bool first = 0; // first -> Tak
        
        ll l = square[0].first - 1, r = n - square[m - 1].first;

        for(int i = 1; i < m; i ++){
            if(square[i].second != square[i - 1].second) dif ++;
            else same ++;
        }

        if(l > r) swap(l, r);
        if(l == 0 and r == 0){

        }else if(l == 0 and r == 1){
            first ^= 1;
        }else if(l == 1 and r == 1){

        }else{
            if(l == r) cout << "Aoki" << endl;
            else cout << "Takahashi" << endl;
            return 0;
        }


        if(same % 2 == 1) first ^= 1;
        if(first == 0) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
}