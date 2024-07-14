#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> P(k + 1), X(k + 1), Q(k + 1), Y(k + 1);
    for(int i = 1; i <= k; i ++){
        cin >> P[i] >> X[i] >> Q[i] >> Y[i];
    }

    vector<int> A(n + 1), big(n + 1, 0), small(n + 1, INT_MAX), choice(n + 1, 0);
    for(int i = 1; i <= k; i ++){
        int p = P[i], x = X[i], q = Q[i], y = Y[i];
        if(x == 1 or y == 1){
            big[p] = max(big[p], x);
            big[q] = max(big[q], y);
            choice[i] = 1;
        }else{
            if(small[p] <= x and small[q] <= y){

            }else{
                if(x > big[p] and y > big[q]){
                    small
                }
            }
        }
    }

}