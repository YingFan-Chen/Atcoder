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
    
    queue<int> Call;
    bitset<500001> Come;

    int person = 1;

    for(int i = 1; i <= q; i ++){
        int a, b;
        cin >> a;
        if(a == 2) cin >> b;

        if(a == 1){
            Call.push(person);
            person ++;
        }else if(a == 2){
            Come[b] = true;
        }else{
            while(Call.size()){
                if(Come[Call.front()] == true){
                    Call.pop();
                }else{
                    break;
                }
            }
            cout << Call.front() << endl;
        }
    }
}