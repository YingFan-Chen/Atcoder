#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int n, m;

struct normal{
    vector<set<pair<int, int>>> v;
    normal(int n){
        v.resize(n);
        for(auto &i : v) i.insert({-1, -1});
    }
    bool check(int x1, int x2, int y1){
        auto it = v[y1].upper_bound({x1, -1});
        if(it != v[y1].end() and x2 > it->first) return false;
        -- it;
        if(x1 < it->second) return false;
        return true;
    }
    void insert(int x1, int x2, int y1){
        v[y1].insert({x1, x2});
    }
};

struct horizontal45{
    vector<set<pair<int, int>>> top, bottom;
    horizontal45(int n){
        top.resize(n);
        bottom.resize(n);
        for(auto &i : top) i.insert({-1, -1});
        for(auto &i : bottom) i.insert({-1, -1});
    }
    bool check(int x1, int x2, int y1){
        int y = x1 + y1;
        if(y >= n){
            y -= n;
            auto it = top[y].upper_bound({x1, -1});
            if(it != top[y].end() and x2 > it->first) return false;
            -- it;
            if(x1 < it->second) return false;
            return true;
        }else{
            auto it = bottom[y].upper_bound({x1, -1});
            if(it != bottom[y].end() and x2 > it->first) return false;
            -- it;
            if(x1 < it->second) return false;
            return true;
        }
    }
    void insert(int x1, int x2, int y1){
        int y = x1 + y1;
        if(x1 > x2) swap(x1, x2);
        if(y >= n) top[y - n].insert({x1, x2});
        else bottom[y].insert({x1, x2});
    }
};

struct vertical45{
    vector<set<pair<int, int>>> right, left;
    vertical45(int n){
        right.resize(n);
        left.resize(n);
        for(auto &i : right) i.insert({-1, -1});
        for(auto &i : left) i.insert({-1, -1});
    } 
    bool check(int x1, int x2, int y1){
        if(x1 >= y1){
            int y = x1 - y1;
            auto it = right[y].upper_bound({x1, -1});
            if(it != right[y].end() and x2 > it->first) return false;
            -- it;
            if(x1 < it->second) return false;
            return true;
        }else{
            int y = y1 - x1;
            auto it = left[y].upper_bound({x1, -1});
            if(it != left[y].end() and x2 > it->first) return false;
            -- it;
            if(x1 < it->second) return false;
            return true;
        }
    }
    void insert(int x1, int x2, int y1){
        if(x1 >= y1){
            int y = x1 - y1;
            if(x1 > x2) swap(x1, x2);
            right[y].insert({x1, x2});
        }else{
            int y = y1 - x1;
            if(x1 > x2) swap(x1, x2);
            left[y].insert({x1, x2});
        }
    }
};

struct closer{
    vector<set<int>> vertical, horizontal;
    vector<set<int>> vt45_right, vt45_left, hor45_top, hor45_bottom;
    closer(int n){
        vertical.resize(n);
        horizontal.resize(n);
        vt45_right.resize(n);
        vt45_left.resize(n);
        hor45_top.resize(n);
        hor45_bottom.resize(n);
        for(auto &i : vertical) i.insert(-1);
        for(auto &i : horizontal) i.insert(-1);
        for(auto &i : vt45_right) i.insert(-1);
        for(auto &i : vt45_left) i.insert(-1);
        for(auto &i : hor45_top) i.insert(-1);
        for(auto &i : hor45_bottom) i.insert(-1);
    }
    void insert(int x, int y){
        vertical[x].insert(y);
        horizontal[y].insert(x);
        if(x + y >= n){
            hor45_top[x + y - n].insert(x);
        }else{
            hor45_bottom[x + y].insert(x);
        }
        if(x >= y){
            vt45_right[x - y].insert(x);
        }else{
            vt45_left[y - x].insert(x);
        }
    }
    pair<int, int> right(int x, int y){
        auto it = horizontal[y].upper_bound(x);
        if(it == horizontal[y].end()) return {-1, -1};
        else return {*it, y};
    }
    pair<int, int> left(int x, int y){
        auto it = -- horizontal[y].lower_bound(x);
        if(*it == -1) return {-1, -1};
        else return {*it, y};
    }
    pair<int, int> up(int x, int y){
        auto it = vertical[x].upper_bound(y);
        if(it == vertical[x].end()) return {-1, -1};
        else return {x, *it};
    }
    pair<int, int> down(int x, int y){
        auto it = -- vertical[x].lower_bound(y);
        if(*it == -1) return {-1, -1};
        else return {x, *it};
    }
    pair<int, int> right45(int x, int y){
        if(x + y >= n){
            auto it = hor45_top[x + y - n].upper_bound(x);
            if(it == hor45_top[x + y - n].end()) return {-1, -1};
            else return {*it, x + y - *it};
        }else{
            auto it = hor45_bottom[x + y].upper_bound(x);
            if(it == hor45_bottom[x + y].end()) return {-1, -1};
            else return {*it, x + y - *it};
        }
    }
    pair<int, int> left45(int x, int y){
        if(x + y >= n){
            auto it = -- hor45_top[x + y - n].lower_bound(x);
            if(*it == -1) return {-1, -1};
            else return {*it, x + y - *it};
        }else{
            auto it = -- hor45_bottom[x + y].lower_bound(x);
            if(*it == -1) return {-1, -1};
            else return {*it, x + y - *it};
        }
    }
    pair<int, int> up45(int x, int y){
        if(x >= y){
            auto it = vt45_right[x - y].upper_bound(x);
            if(it == vt45_right[x - y].end()) return {-1, -1};
            else return {*it, *it - x + y};
        }else{
            auto it = vt45_left[y - x].upper_bound(x);
            if(it == vt45_left[y - x].end()) return {-1, -1};
            else return {*it, *it + y - x};
        }
    }
    pair<int, int> down45(int x, int y){
        if(x >= y){
            auto it = -- vt45_right[x - y].lower_bound(x);
            if(*it == -1) return {-1, -1};
            else return {*it, *it - x + y};
        }else{
            auto it = -- vt45_left[y - x].lower_bound(x);
            if(*it == -1) return {-1, -1};
            else return {*it, *it + y - x};
        }
    }
};

struct square{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    int w, type, pos;
    square(int x1_, int y1_, int x2_, int y2_, int x3_, int y3_, int x4_, int y4_, int type_, int pos_){
        x1 = x1_; y1 = y1_; x2 = x2_; y2 = y2_; x3 = x3_; y3 = y3_; x4 = x4_; y4 = y4_;
        type = type_;
        pos = pos_;
        int c = (n - 1) / 2;
        w = (x1 - c) * (x1 - c) + (y1 - c) * (y1 - c) + 1;
    }
};

struct cmp{
    bool operator() (square &a, square &b){
        if(a.w < b.w) return true;
        else return false;
    }
};

void add(priority_queue<square, vector<square>, cmp> &pq, int i, int j, closer &t){
    auto left = t.left(i, j);
    auto right = t.right(i, j);
    auto up = t.up(i, j);
    auto down = t.down(i, j);
    if(right.first != -1 and up.first != -1) pq.push(square {right.first, up.second, up.first, up.second, i, j, right.first, right.second, 1, 1});
    if(left.first != -1 and up.first != -1) pq.push(square {left.first, up.second, left.first, left.second, i, j, up.first, up.second, 1, 2});
    if(left.first != -1 and down.first != -1) pq.push(square {left.first, down.second, down.first, down.second, i, j, left.first, left.second, 1, 3});
    if(right.first != -1 and down.first != -1) pq.push(square {right.first, down.second, right.first, right.second, i, j, down.first, down.second, 1, 4});
    auto left45 = t.left45(i, j);
    auto right45 = t.right45(i, j);
    auto up45 = t.up45(i, j);
    auto down45 = t.down45(i, j);
    if(right45.first != -1 and up45.first != -1) pq.push(square {(up45.first + up45.second + right45.first - right45.second) / 2, (up45.first + up45.second - right45.first + right45.second) / 2, up45.first, up45.second, i, j, right45.first, right45.second, 2, 1});
    if(left45.first != -1 and up45.first != -1) pq.push(square {(up45.first + up45.second + left45.first - left45.second) / 2, (up45.first + up45.second - left45.first + left45.second) / 2, left45.first, left45.second, i, j, up45.first, up45.second, 2, 2});
    if(left45.first != -1 and down45.first != -1) pq.push(square {(down45.first + down45.second + left45.first - left45.second) / 2, (down45.first + down45.second - left45.first + left45.second) / 2, down45.first, down45.second, i, j, left45.first, left45.second, 2, 3});
    if(right45.first != -1 and down45.first != -1) pq.push(square {(down45.first + down45.second + right45.first - right45.second) / 2, (down45.first + down45.second - right45.first + right45.second) / 2, right45.first, right45.second, i, j, down45.first, down45.second, 2, 4});
}

bool check(square s, vector<vector<int>> &dot, closer &t, normal &h, normal &v, horizontal45 &h45, vertical45 &v45){
    if(dot[s.x1][s.y1] == 1) return false;
    if(s.type == 1){
        auto left1 = t.left(s.x1, s.y1);
        auto right1 = t.right(s.x1, s.y1);
        auto up1 = t.up(s.x1, s.y1);
        auto down1 = t.down(s.x1, s.y1);
        pair<int, int> dot2 = {s.x2, s.y2}, dot4 = {s.x4, s.y4};
        if(dot2 != left1 and dot2 != right1 and dot2 != up1 and dot2 != down1) return false;
        if(dot4 != left1 and dot4 != right1 and dot4 != up1 and dot4 != down1) return false;
        auto left3 = t.left(s.x3, s.y3);
        auto right3 = t.right(s.x3, s.y3);
        auto up3 = t.up(s.x3, s.y3);
        auto down3 = t.down(s.x3, s.y3);
        if(dot2 != left3 and dot2 != right3 and dot2 != up3 and dot2 != down3) return false;
        if(dot4 != left3 and dot4 != right3 and dot4 != up3 and dot4 != down3) return false;

        if(s.pos == 1){
            if(h.check(s.x3, s.x4, s.y3) and h.check(s.x2, s.x1, s.y2) and v.check(s.y3, s.y2, s.x3) and v.check(s.y4, s.y1, s.x4)) return true;
        }else if(s.pos == 2){
            if(h.check(s.x2, s.x3, s.y2) and h.check(s.x1, s.x4, s.y1) and v.check(s.y2, s.y1, s.x2) and v.check(s.y3, s.y4, s.x3)) return true;
        }else if(s.pos == 3){
            if(h.check(s.x1, s.x2, s.y1) and h.check(s.x4, s.x3, s.y4) and v.check(s.y1, s.y4, s.x1) and v.check(s.y2, s.y3, s.x2)) return true;
        }else{
            if(h.check(s.x4, s.x1, s.y4) and h.check(s.x3, s.x2, s.y3) and v.check(s.y4, s.y3, s.x4) and v.check(s.y1, s.y2, s.x1)) return true;
        }
        return false;
    }else{
        auto left1 = t.left45(s.x1, s.y1);
        auto right1 = t.right45(s.x1, s.y1);
        auto up1 = t.up45(s.x1, s.y1);
        auto down1 = t.down45(s.x1, s.y1);
        pair<int, int> dot2 = {s.x2, s.y2}, dot4 = {s.x4, s.y4};
        if(dot2 != left1 and dot2 != right1 and dot2 != up1 and dot2 != down1) return false;
        if(dot4 != left1 and dot4 != right1 and dot4 != up1 and dot4 != down1) return false;
        auto left3 = t.left45(s.x3, s.y3);
        auto right3 = t.right45(s.x3, s.y3);
        auto up3 = t.up45(s.x3, s.y3);
        auto down3 = t.down45(s.x3, s.y3);
        if(dot2 != left3 and dot2 != right3 and dot2 != up3 and dot2 != down3) return false;
        if(dot4 != left3 and dot4 != right3 and dot4 != up3 and dot4 != down3) return false;

        if(s.pos == 1){
            if(h45.check(s.x3, s.x4, s.y3) and h45.check(s.x2, s.x1, s.y2) and v45.check(s.x3, s.x2, s.y3) and v45.check(s.x4, s.x1, s.y4)) return true;
        }else if(s.pos == 2){
            if(h45.check(s.x2, s.x3, s.y2) and h45.check(s.x1, s.x4, s.y1) and v45.check(s.x2, s.x1, s.y2) and v45.check(s.x3, s.x4, s.y3)) return true;
        }else if(s.pos == 3){
            if(h45.check(s.x1, s.x2, s.y1) and h45.check(s.x4, s.x3, s.y4) and v45.check(s.x1, s.x4, s.y1) and v45.check(s.x2, s.x3, s.y2)) return true;
        }else{
            if(h45.check(s.x4, s.x1, s.y4) and h45.check(s.x3, s.x2, s.y3) and v45.check(s.x4, s.x3, s.y4) and v45.check(s.x1, s.x2, s.y1)) return true;
        }
        return false;
    }
}

int main(){
    cin >> n >> m;
    vector<vector<int>> dot(n, vector<int> (n));
    closer t(n);
    vector<vector<int>> res;
    normal h(n), v(n);
    horizontal45 h45(n);
    vertical45 v45(n);
    for(int i = 0; i < m; i ++){
        int x, y;
        cin >> x >> y;
        dot[x][y] = 1;
        t.insert(x, y);
    }
    /* To Do */
    priority_queue<square, vector<square>, cmp> pq;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(dot[i][j] == 1) add(pq, i, j, t);
        }
    }

    /*cout << pq.size() << endl;
    while(pq.size()){
        if(check(pq.top()))
        cout << pq.top().x1 << " " << pq.top().y1 << " " << pq.top().x2 << " " << pq.top().y2 << " " << pq.top().x3 << " " << pq.top().y3 << " " << pq.top().x4 << " " << pq.top().y4 << endl;
        pq.pop();
    }*/

    while(pq.size()){
        if(check(pq.top(), dot, t, h, v, h45, v45)){
            res.push_back(vector<int> {pq.top().x1, pq.top().y1, pq.top().x2, pq.top().y2, pq.top().x3, pq.top().y3, pq.top().x4, pq.top().y4});
            dot[pq.top().x1][pq.top().y1] = 1;
            t.insert(pq.top().x1, pq.top().y1);
            
            square s = pq.top();
            if(s.type == 1){
                if(s.pos == 1){
                    h.insert(s.x3, s.x4, s.y3);
                    h.insert(s.x2, s.x1, s.y2);
                    v.insert(s.y3, s.y2, s.x3);
                    v.insert(s.y4, s.y1, s.x4);
                }else if(s.pos == 2){
                    h.insert(s.x2, s.x3, s.y2);
                    h.insert(s.x1, s.x4, s.y1);
                    v.insert(s.y2, s.y1, s.x2);
                    v.insert(s.y3, s.y4, s.x3);
                }else if(s.pos == 3){
                    h.insert(s.x1, s.x2, s.y1);
                    h.insert(s.x4, s.x3, s.y4);
                    v.insert(s.y1, s.y4, s.x1);
                    v.insert(s.y2, s.y3, s.x2);
                }else{
                    h.insert(s.x4, s.x1, s.y4);
                    h.insert(s.x3, s.x2, s.y3);
                    v.insert(s.y4, s.y3, s.x4);
                    v.insert(s.y1, s.y2, s.x1);
                }
            }else{
                if(s.pos == 1){
                    h45.insert(s.x3, s.x4, s.y3);
                    h45.insert(s.x2, s.x1, s.y2);
                    v45.insert(s.x3, s.x2, s.y3);
                    v45.insert(s.x4, s.x1, s.y4);
                }else if(s.pos == 2){
                    h45.insert(s.x2, s.x3, s.y2);
                    h45.insert(s.x1, s.x4, s.y1);
                    v45.insert(s.x2, s.x1, s.y2);
                    v45.insert(s.x3, s.x4, s.y3);
                }else if(s.pos == 3){
                    h45.insert(s.x1, s.x2, s.y1);
                    h45.insert(s.x4, s.x3, s.y4);
                    v45.insert(s.x1, s.x4, s.y1);
                    v45.insert(s.x2, s.x3, s.y2);
                }else{
                    h45.insert(s.x4, s.x1, s.y4);
                    h45.insert(s.x3, s.x2, s.y3);
                    v45.insert(s.x4, s.x3, s.y4);
                    v45.insert(s.x1, s.x2, s.y1);
                }
            }

            add(pq, pq.top().x1, pq.top().y1, t);
            add(pq, pq.top().x2, pq.top().y2, t);
            add(pq, pq.top().x3, pq.top().y3, t);
            add(pq, pq.top().x4, pq.top().y4, t);
        }
        pq.pop();
    }
    
    cout << res.size() << endl;
    for(auto &i : res){
        cout << i[0] << " " << i[1] << " " << i[2] << " " << i[3] <<  " " << i[4] << " " << i[5] << " " << i[6] << " " << i[7] << endl;
    }
} 