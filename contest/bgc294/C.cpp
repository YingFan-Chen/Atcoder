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
    queue<int> A, B;
    for(int i = 0; i < n; i ++){
        int t; cin >> t;
        A.push(t);
    }
    for(int i = 0; i < m; i ++){
        int t; cin >> t;
        B.push(t);
    }
    vector<int> res1, res2;
    for(int i = 1; i <= n + m; i ++){
        if(A.size() and B.size()){
            if(A < B){
                A.pop();
                res1.push_back(i);
            }else{
                B.pop();
                res2.push_back(i);
            }
        }else if(A.size()){
            A.pop();
            res1.push_back(i);
        }else{
            B.pop();
            res2.push_back(i);
        }
    }
    for(auto i : res1) cout << i << " ";
    cout << endl;
    for(auto i : res2) cout << i << " ";
    cout << endl;
}