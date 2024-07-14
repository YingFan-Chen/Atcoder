#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<char>> A(N, vector<char> (N)), B(N, vector<char> (N));;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            cin >> A[i][j];
            B[i][j] = A[i][j];
        }
    }

    for(int i = 1; i < N; i ++){
        B[0][i] = A[0][i - 1];
        B[i][N - 1] = A[i - 1][N - 1];
        B[N - 1][N - 1 - i] = A[N - 1][N - i];
        B[N - 1 - i][0] = A[N - i][0]; 
    }

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            cout << B[i][j];
        }
        cout << endl;
    }

}