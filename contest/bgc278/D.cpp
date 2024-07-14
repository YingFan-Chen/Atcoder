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
    vector<ll> A(n + 1);
    vector<pair<ll, ll>> add(n + 1);    // first -> timne, second -> val
    for(int i = 1; i <= n; i ++) cin >> A[i];
    int q;
    cin >> q;
    ll reset = -1, time = -1;
    for(int i = 0; i < q; i ++){
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            int x;
            cin >> x;
            reset = x;
            time = i;
        }else if(tmp == 2){
            int j, x;
            cin >> j >> x;
            if(add[j].first > time){
                add[j].first = i;
                add[j].second += x;
            }else{
                add[j].first = i;
                add[j].second = x;
            }
        }else{
            int j;
            cin >> j;
            if(time < 0){
                cout << A[j] + add[j].second << endl;
            }else{
                if(time > add[j].first) cout << reset << endl;
                else cout << reset + add[j].second << endl;
            }
        }
    }
}