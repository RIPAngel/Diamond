#include <iostream>
#include <queue>
#include <vector>
#define fi first
#define se second
using namespace std;
const int IND = 1005;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int d[2][IND][IND], arr[IND][IND], n, m;
struct pos {
    int t;
    int x;
    int y;
};
bool chkOver (int x, int y) {
    return (x >= 1 && y >= 1 && x <= n && y <= m);
}
int bfs (int xx, int yy) {
    queue <pos>q;
    q.push({0, xx, yy});
    d[0][xx][yy] = 1;
    while (!q.empty()) {
        pos t = {q.front().t, q.front().x, q.front().y};
        q.pop();
        if (t.x == n && t.y == m) return d[t.t][t.x][t.y];
        for (int i = 0; i < 4; ++i) {
            int xx = dx[i] + t.x;
            int yy = dy[i] + t.y;
            if (chkOver(xx, yy)){
                if (arr[xx][yy] && t.t == 0 && !d[1][xx][yy]) {
                    d[1][xx][yy] = d[t.t][t.x][t.y] + 1;
                    q.push({1, xx, yy});
                }
                else if (!arr[xx][yy] && !d[t.t][xx][yy]) {
                    d[t.t][xx][yy] = d[t.t][t.x][t.y] + 1;
                    q.push({t.t, xx, yy});
                }
            }
        }
    }
    return -1;
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%1d", &arr[i][j]);
        }
    }
    cout << bfs(1, 1);
    return 0;
}

    