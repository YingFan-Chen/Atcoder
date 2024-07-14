#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int H, W, rs, cs;
    cin >> H >> W >> rs >> cs;
    
    int N;
    cin >> N;
    unordered_map<int, set<int>> row, column;
    for(int i = 1; i <= N; i ++){
        int r, c;
        cin >> r >> c;
        row[r].insert(c);
        column[c].insert(r);
    }

    int Q;
    cin >> Q;
    for(int i = 1; i <= Q; i ++){
        char d;
        int l;
        cin >> d >> l;
        if(d == 'L'){
            int rt = rs, ct = cs - l;
            if(row[rs].lower_bound(cs) == row[rt].lower_bound(ct)){
                rs = rt;
                cs = max(ct, 1);
            }else{
                rs = rt;
                cs = *(-- row[rs].lower_bound(cs)) + 1;
            }
        }else if(d == 'R'){
            int rt = rs, ct = cs + l;
            if(row[rs].upper_bound(cs) != row[rs].end()){
                rs = rt;
                cs = min(ct, *row[rs].upper_bound(cs) - 1);
            } else{
                rs = rt;
                cs = min(ct, W);
            }
        }else if(d == 'U'){
            int rt = rs - l, ct = cs;
            if(column[cs].lower_bound(rs) == column[ct].lower_bound(rt)){
                rs = max(rt, 1);
                cs = ct;
            }else{
                rs = *(-- column[cs].lower_bound(rs)) + 1;
                cs = ct;
            }
        }else{
            int rt = rs + l, ct = cs;
            if(column[cs].upper_bound(rs) != column[cs].end()){
                rs = min(rt, *column[cs].upper_bound(rs) - 1);
                cs = ct;
            } else{
                rs = min(rt, H);
                cs = ct;
            }
        }
        cout << rs << " " << cs << endl;
    }
}