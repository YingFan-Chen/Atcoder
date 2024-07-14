#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

bool f(int a, int b, int c, int d){
    swap(b, c);
    int h = 10 * a + b, m = 10 * c + d;
    if(h >= 0 and h <= 23){
        if(m >= 0 and m <= 59)
            return true;
    }
    return false;
}

int main(){
    int h, m;
    cin >> h >> m;
    while(true){
        if(f(h / 10, h % 10, m / 10, m % 10)){
            cout << h << " " << m << endl;
            return 0;
        }
        m ++;
        if(m >= 60){
            h ++;
            m = 0;
            if(h >= 24) h = 0;
        }
    }
}