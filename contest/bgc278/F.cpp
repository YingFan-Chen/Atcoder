#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int n;
vector<string> S;
vector<int> use;

bool DFS(string str){
    bool res = false;
    for(int i = 0; i < n; i ++){
        if(use[i] == 0 and str[str.size() - 1] == S[i][0]){
            use[i] = 1;
            bool tmp = DFS(S[i]);
            use[i] = 0;
            if(tmp == false){
                res = true;
                break;
            }
        }
    }
    return res;
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        string tmp;
        cin >> tmp;
        S.push_back(tmp);
    }
    use.resize(n);
    for(int i = 0; i < n; i ++){
        use[i] = 1;
        bool tmp = DFS(S[i]);
        use[i] = 0;
        if(tmp == false){
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
}