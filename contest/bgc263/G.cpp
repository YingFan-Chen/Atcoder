#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;
#define kN 10'000'000 + 5

int IsPrime[kN];

struct edge{
public:
    ll flow, capacity;
    edge(ll _flow, ll _capacity) : flow(_flow), capacity(_capacity) {}
};

void SetupIsPrime(){
    vector<int> Prime;
    for(int i = 2; i <= kN; i ++){
        if(IsPrime[i] == 0){
            IsPrime[i] = i;
            Prime.push_back(i);
        }
        for(int j = 0; j < Prime.size() and Prime[j] <= IsPrime[i] and i * Prime[j] <= kN; j ++){
            IsPrime[i * Prime[j]] = Prime[j];
        }
    }
}

/*ll f(vector<vector<edge>> residual){
    vector<vector<edge>> level(105, vector<edge> (105));

}*/

int main(){
    int n;
    cin >> n;
    vector<ll> A(n + 1), B(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> A[i] >> B[i];
    }

    memset(IsPrime, 0, kN * 4);
    SetupIsPrime();

    ll number_of_one = 0; 
    vector<vector<edge>> graph(105, vector<edge> (105));
    for(int i = 1; i <= n; i ++){
        if(A[i] == 1){
            number_of_one = B[i];
        }else{
            if(A[i] & 1){
                graph[0][i] = {0, B[i]};
            }else{
                graph[i][n + 1] = {0, B[i]};
            }
        }
    }
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
           if(A[i] != 1 and A[j] != 1){
                ll tmp = A[i] + A[j];
                if(IsPrime[tmp] == 0){
                    graph[i][j] = {0, min(B[i], B[j])};
                }
           }
        }
    }
    
    for(auto i : graph){
        for(auto j : i){
            cout << j.capacity << " ";
        }
        cout << endl;
    }
}
