//timeout code
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <limits>
#define fi first
#define se second
using namespace std;
int n, k, res = 2147483646;
pair <int, int> points[505];

int distanceCalc (int a, int b) {
    return abs (points[a].fi - points[b].fi) + abs (points[a].se - points[b].se); 
}

void dfs (int num, int distance, int skipCnt) {
    if (num >= (n - 1)) {
        if (distance < res) {
            res = distance;
        }
        return;
    }
    else {
        if (skipCnt >= k) {
            dfs (num + 1, distance + distanceCalc (num, num + 1), skipCnt);
        }
        else {
            dfs (num + 1, distance + distanceCalc (num, num + 1), skipCnt);
            dfs (num + 2, distance + distanceCalc (num, num + 2), skipCnt + 1);
        }
    }
}

int main () {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {;
        cin >> points[i].fi >> points[i].se;
    }
    dfs (0, 0, 0);
    cout << res;
    return 0;
}