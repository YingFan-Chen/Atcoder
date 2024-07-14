#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#endif
using namespace std;

/***********************************
Strategy : Sliding Window
***********************************/

struct Point{
    ll x, y;
};

ll triangleArea(Point a, Point b, Point c){
    ll res = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    res = abs(res) * 4;
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<Point> points;
    for(int i = 1; i <= n; i ++){
        ll x, y;
        cin >> x >> y;
        points.push_back(Point {x, y});
    }

    ll totalArea = 0;
    for(int i = 1; i < n - 1; i ++){
        totalArea += triangleArea(points[0], points[i], points[i + 1]);
    }
    ll targetArea = totalArea / 4;

    ll curArea = 0, res = ll_max;
    for(int p = 0, q = 2; q < n; q ++){
        curArea += triangleArea(points[p], points[q - 1], points[q]);
        res = min(res, abs(curArea - targetArea));
        while(curArea >= targetArea){
            curArea -= triangleArea(points[p], points[p + 1], points[q]);
            res = min(res, abs(curArea - targetArea));
            p ++;
        }
    }

    targetArea *= 3;
    curArea = 0;
    for(int p = 0, q = 2; q < n; q ++){
        curArea += triangleArea(points[p], points[q - 1], points[q]);
        res = min(res, abs(curArea - targetArea));
        while(curArea >= targetArea){
            curArea -= triangleArea(points[p], points[p + 1], points[q]);
            res = min(res, abs(curArea - targetArea));
            p ++;
        }
    }

    cout << res << endl;
}