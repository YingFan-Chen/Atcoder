#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    if(r > 8) r = 8 - (r - 8);
    char ch;
    if(r == 1) ch = 'b';
    if(r == 2){
        if(c == 1 or c == 15) ch = 'b';
        else ch = 'w';
    }
    if(r == 3){
        if(c == 2 or c == 14) ch = 'w';
        else ch = 'b';
    }
    if(r == 4){
        if(c == 1 or c == 3 or c == 13 or c == 15) ch = 'b';
        else ch = 'w';
    }
    if(r == 5){
        if(c == 2 or c == 4 or c == 12 or c == 14) ch = 'w';
        else ch = 'b';
    }
    if(r == 6){
        if(c == 1 or c == 3 or c == 5 or c == 11 or c == 13 or c == 15) ch = 'b';
        else ch = 'w';
    }
    if(r == 7){
        if(c == 2 or c == 4 or c == 6 or c== 10 or c == 12 or c == 14) ch = 'w';
        else ch = 'b';
    }
    if(r == 8){
        if(c == 1 or c == 3 or c == 5 or c == 7 or c == 9 or c == 11 or c == 13 or c == 15) ch = 'b';
        else ch = 'w';
    }
    if(ch == 'b') cout << "black" << endl;
    else cout << "white" << endl;
}