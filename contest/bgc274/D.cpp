#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> A(n + 1);
    for(int i = 1; i <= n; i ++) cin >> A[i];
    vector<unordered_set<int>> odd(n / 2 + 5), even(n / 2 + 5);
    odd[0].insert(0);
    even[0].insert(0);
    for(int i = 1; 2 * i <= n; i ++){
        for(auto tmp : even[i - 1]){
            even[i].insert(tmp + A[2 * i]);
            even[i].insert(tmp - A[2 * i]);
        }
    }
    for(int i = 1; 2 * i + 1 <= n; i ++){
        for(auto tmp : odd[i - 1]){
            odd[i].insert(tmp + A[2 * i + 1]);
            odd[i].insert(tmp - A[2 * i + 1]);
        }
    }

    if(n % 2){
        if(odd[n / 2].find(x - A[1]) != odd[n / 2].end() and even[n / 2].find(y) != even[n / 2].end()) 
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }else{
        if(odd[n / 2 - 1].find(x - A[1]) != odd[n / 2 - 1].end() and even[n / 2].find(y) != even[n / 2].end()) 
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
}