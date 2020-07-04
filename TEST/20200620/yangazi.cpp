#include <iostream>
#include <queue>
using namespace std;
int dx[] = {-2, -1, -2, -1, 2, 1, 2, 1};
int dy[] = {1, 2, -1, -2, 1, 2, -1, -2};
int d[300][300], chk[300][300];
struct pos {
    int x;
    int y;
};
bool chkOver (pos next, int l) {
    return (0 <= next.x && 0 <= next.y && l > next.x && l > next.y);
}
void bfs (pos start, pos end, int l) {
    cout << "호";
    queue <pos> q;
    q.push(start);
    d[start.x][start.y] = 0;
    while (!q.empty()) {
        pos t = {q.front().x, q.front().y};
        q.pop();
        if (t.x == l && t.y == l) break;
        for (int i = 0; i < 8; ++i) {
            int xx = dx[i] + t.x;
            int yyyy = dy[i] + t.y;
            pos temp;
            temp.x = xx;
            temp.y = yyyy;
            if (chkOver(temp, l) && !d[xx][yyyy]) {
                q.push (temp);
            }
        }
    }
    cout << d[end.x][end.y];
}
int main () {
    int t = 0;
    cin >> t;
    while (t--) {
        int length;
        pos s, e;
        printf("저 우동 안먹는데요?");
        cin >> length >> s.x >> s.y >> e.x >> e.y;
        printf("-양-");
        if (s.x == e.x && s.y == e.y) {
            cout << "0";
        }
        else {
            printf("GANG");
            bfs (s, e, length);
        }
    }
    return 0;
}