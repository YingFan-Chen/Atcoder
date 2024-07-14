#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "C:\Users\josep\code\c++\lib\debug"
#endif
using namespace std;

/*
    BBAA -> BABA -> BAAB
    BBAB -> BABB -> BAAB
    ABAA -> AABA -> ABBA
*/

int main(){
    int n;
    string s;
    cin >> n >> s;
    if(s[0] == 'A' and s[n - 1] == 'B'){
        cout << "No" << endl;
        return 0;
    }
    
    if(n == 2 and s == "BA"){
        cout << "No" << endl;
        return 0;
    }
    

    cout << "Yes" << endl;
}