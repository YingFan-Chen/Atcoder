#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> t(q), a(q), b(q);
    for(int i = 0; i < q; i ++){
        cin >> t[i] >> a[i] >> b[i];
    }
    unordered_map<int, unordered_set<int>> relation;
    for(int i = 0; i < q; i ++){
        if(t[i] == 1){
            relation[a[i]].insert(b[i]);
        }else if(t[i] == 2){
            if(relation[a[i]].find(b[i]) != relation[a[i]].end())
                relation[a[i]].erase(b[i]);
        }else{
            if(relation[a[i]].find(b[i]) != relation[a[i]].end()){
                if(relation[b[i]].find(a[i]) != relation[b[i]].end())
                    cout << "Yes" << endl;
                else cout << "No" << endl;
            }else cout << "No" << endl;
        }
    } 
}