#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

bool f(int pos, int x, int y){
    if(x > pos and y > pos and x > y) return true;
    if(x < pos and y < pos and x < y) return true;
    return false; 
}

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    if(f(0, x, y)){
        if(x > 0){
            if(z < 0){
                cout << 2 * abs(z) + abs(x) << endl;
            }else{
                if(f(0, z, y)){
                    cout << -1 << endl;
                    return 0;
                }else{
                    cout << abs(x) << endl;
                    return 0;
                }
            }
        }else{
            if(z > 0){
                cout << 2 * abs(z) + abs(x) << endl;
            }else{
                if(f(0, z, y)){
                    cout << -1 << endl;
                    return 0;
                }else{
                    cout << abs(x) << endl;
                    return 0;
                }
            }
        }
    }else{
        cout << abs(x) << endl;
        return 0;
    }
}