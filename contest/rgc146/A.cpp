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
    vector<int> A(n);
    for(int i = 0; i < n; i ++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    int a = A[n - 1], b = A[n - 2], c = A[n - 3];
    vector<string> tmp;
    tmp.push_back(to_string(a));
    tmp.push_back(to_string(b));
    tmp.push_back(to_string(c));
    sort(tmp.begin(), tmp.end());
    cout << tmp[2] << tmp[1] << tmp[0] << endl;
}