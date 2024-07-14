#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> P(n + 1), Pos(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> P[i];
        Pos[P[i]] = i;
    }
    vector<pair<int, int>> res;
    
    vector<int> even, odd;
    for(int i = 1; i <= n; i ++){
        if(i % 2 and Pos[i] % 2 == 0){
            odd.push_back(i);
        }
        if(i % 2 == 0 and Pos[i] % 2){
            even.push_back(i);
        }
    }
    while(even.size()){
        int a = *even.rbegin(), b = *odd.rbegin();
        even.pop_back();
        odd.pop_back();
        if(Pos[a] > Pos[b]) swap(a, b);
        for(int i = Pos[a]; i != Pos[b] - 1; i += 2){
            int tmp = P[i + 2];
            swap(P[i], P[i + 2]);
            swap(Pos[a], Pos[tmp]);
            res.push_back({2, i});
        }
        res.push_back({1, Pos[a]});
        swap(P[Pos[a]], P[Pos[b]]);
        swap(Pos[a], Pos[b]);
    }

    for(int i = 1; i <= n; i += 2){
        while(Pos[i] != i){
            res.push_back({2, Pos[i] - 2});
            int tmp = P[Pos[i] - 2];
            swap(P[Pos[i]], P[Pos[i] - 2]);
            swap(Pos[i], Pos[tmp]);
        }
    }
    for(int i = 2; i <= n; i += 2){
        while(Pos[i] != i){
            res.push_back({2, Pos[i] - 2});
            int tmp = P[Pos[i] - 2];
            swap(P[Pos[i]], P[Pos[i] - 2]);
            swap(Pos[i], Pos[tmp]);
        }
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i ++){
        if(res[i].first == 1) cout << "A" << " ";
        else cout << "B" << " ";
        cout << res[i].second << endl;
    }
}