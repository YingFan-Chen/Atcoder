#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

const int N = 10000000;
vector<int> lp(N+1);
vector<int> pr;

int main(){
    int n;
    cin >> n;
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }

    vector<vector<int>> res(n, vector<int> (n));

    if(n % 2){
        int mid = n / 2;
        res[mid][mid] = 7;
        res[mid][mid + 1] = 2;
        res[mid + 1][mid] = 8;
        res[mid + 1][mid - 1] = 1;
        unordered_set<int> s = {7, 2, 8, 1};
        vector<pair<int, int>> v;
        for(int i = 1; i <= n * n; i += 2){
            if(v.size() == n - 2) break;
            for(int j = 2; j <= n * n; j += 2){
                if(s.find(i) == s.end() and s.find(j) == s.end() and lp[i + j] != i + j){
                    v.push_back({i, j});
                    s.insert(i);
                    s.insert(j);
                    break;
                }
            }
        }
        int count = 0;
        for(int i = mid + 2; i < n; i ++){
            res[i][mid - 1] = v[count].first;
            res[i][mid] = v[count].second;
            count ++;
        }
        for(int i = 0; i < mid; i ++){
            res[i][mid] = v[count].first;
            res[i][mid + 1] = v[count].second;
            count ++;
        }
        int odd = 1;
        for(int j = 0; j < mid; j ++){
            for(int i = 0; i < n; i ++){
                if(j == mid - 1 and i == mid + 1) break;
                while(s.find(odd) != s.end()) odd += 2;
                res[i][j] = odd;
                odd += 2;
            }
        }
        int even = 2;
        for(int i = 0; i < n; i ++){
            for(int j = mid; j < n; j ++){
                while(s.find(even) != s.end()) even += 2;
                if(res[i][j] == 0) res[i][j] = even, even += 2;
            }
        } 

    }else{
        int mid = n / 2 - 1;
        vector<pair<int, int>> v;
        unordered_set<int> s;
        for(int i = 1; i <= n * n; i += 2){
            if(v.size() == n) break;
            for(int j = 2; j <= n * n; j += 2){
                if(s.find(j) == s.end() and lp[i + j] != i + j){
                    v.push_back({i, j});
                    s.insert(i);
                    s.insert(j);
                    break;
                }
            }
        }

        for(int i = 0; i < n; i ++){
            res[i][mid] = v[i].first;
            res[i][mid + 1] = v[i].second;
        }
        int odd = 1;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < mid; j ++){
                while(s.find(odd) != s.end()) odd += 2;
                res[i][j] = odd;
                odd += 2;
            }
        }
        int even = 2;
        for(int i = 0; i < n; i ++){
            for(int j = mid + 2; j < n; j ++){
                while(s.find(even) != s.end()) even += 2;
                res[i][j] = even;
                even += 2;
            }
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}