#include <iostream>
#include <queue>
#include <vector>
#define fi first
#define se second
using namespace std;
const int IND = 105;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int d[IND][IND], arr[IND][IND], n, m;

bool chkOver (int x, int y) {
    return (x >= 1 && y >= 1 && x <= n && y <= m);
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%1d", &arr[i][j]);
        }
    }
    queue <pair <int, int> >q;
    q.push({1, 1});
    d[1][1] = 1;
    while (!q.empty()) {
        pair <int, int> t = {q.front().fi, q.front().se};
        q.pop();
        if (t.fi == n && t.se == m) break;
        for (int i = 0; i < 4; ++i) {
            int xx = dx[i] + t.fi;
            int yy = dy[i] + t.se;
            if (chkOver(xx, yy) && !d[xx][yy] && arr[xx][yy]) {
                d[xx][yy] = d[t.fi][t.se] + 1;
                q.push ({xx, yy});
            }
        }
    }
    cout << d[n][m];
    return 0;
}

    