#include <bits/stdc++.h>
#define ll long long
#define ll_max LONG_LONG_MAX
#ifndef ONLINE_JUDGE
#include "..\..\lib\debug"
#endif
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    double tmp = (double) b / (double) a;
    printf("%.3f", tmp);
}