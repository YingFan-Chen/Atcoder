#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll maximum){
    string s = to_string(maximum);
    int n = s.size();
    ll res = 0;
    for(int i = 1; i < n; i ++){
        res *= 10;
        res += 9;
    }

    for(int i = 1; i <= n / 2; i ++){
        if(n % i == 0){
            string tmp = s.substr(0, i);
            ll p = stoll(tmp), k = pow(10, i), r = 0;

            for(int j = 0; j < n / i; j ++){
                r *= k;
                r += p;
            }

            if(r <= maximum){
                res = max(r, res);
            }else{
                p --;
                r = 0;
                for(int j = 0; j < n / i; j ++){
                    r *= k;
                    r += p;
                }
                res = max(r, res);
            }
        }
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    vector<ll> Case(t);
    for(int i = 0; i < t; i ++){
        cin >> Case[i];        
    }

    for(int i = 0; i < t; i ++){
        cout << solve(Case[i]) << endl;
    }
}