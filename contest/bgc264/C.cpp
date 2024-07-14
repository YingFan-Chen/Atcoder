#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

void f1(vector<vector<int>> &r, vector<int> &tmp, int h2, int count, int h1){
    if(count >= h1) return;
    f1(r, tmp, h2, count + 1, h1);
    tmp.push_back(count);
    if(tmp.size() == h2) r.push_back(tmp);
    else f1(r, tmp, h2, count + 1, h1);
    tmp.pop_back();
}



int main(){
    int h1, w1, h2, w2;
    cin >> h1 >> w1;
    int A[h1][w1];
    for(int i = 0; i < h1; i ++){
        for(int j = 0; j < w1; j ++)
            cin >> A[i][j];
    }
    cin >> h2 >> w2;
    int B[h2][w2];
    for(int i = 0; i < h2; i ++){
        for(int j = 0; j < w2; j ++)
            cin >> B[i][j];
    }

    vector<vector<int>> r, c;
    vector<int> tmp;
    f1(r, tmp, h2, 0, h1);
    tmp.clear();
    f1(c, tmp, w2, 0, w1);

    ll total = 0;
    for(int i = 0; i < h2; i ++){
        for(int j = 0; j < w2; j ++){
            total += B[i][j];
        }
    }

    for(auto &i : r){
        for(auto &j : c){
            int flag = 1;
            for(int x = 0; x < i.size(); x ++){
                for(int y = 0; y < j.size(); y ++){
                    if(A[i[x]][j[y]] != B[x][y]) flag = 0;
                }
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}