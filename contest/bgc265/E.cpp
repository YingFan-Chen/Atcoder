#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;
static constexpr ll mod = 998244353;
ll A, B, C, D, E, F;
int dp[301][301][301];

pair<ll, ll> f(ll x, ll y, ll z){
    ll a = x * A + y * C + z * E;
    ll b = x * B + y * D + z * F;
    return {a, b};
}

int main(){ 
    int n, m;
    cin >> n >> m;
    cin >> A >> B >> C >> D >> E >> F;
    set<pair<ll, ll>> s;
    for(int i = 1; i <= m; i ++){
        ll x, y;
        cin >> x >> y;
        s.insert({x, y});
    }

    memset(dp, 0, sizeof(dp));    
    dp[0][0][0] = 1;

    ll res = 0;
    for(int i = 1; i <= n; i ++){
        for(int x = 0; x <= i; x ++){
            for(int y = 0; y <= i - x; y ++){
                int z = i - x - y;
                pair<ll, ll> tmp = f(x, y, z);
                if(s.find(tmp) != s.end()){
                    dp[x][y][z] = 0;
                }else{
                    ll count = 0;
                    if(x > 0) count += dp[x - 1][y][z];
                    if(y > 0) count += dp[x][y -1][z];
                    if(z > 0) count += dp[x][y][z - 1];
                    count %= mod;
                    dp[x][y][z] = count;
                }
                if(i == n) res = (res + dp[x][y][z]) % mod;
            }
        }
    }
    cout << res << endl;
}