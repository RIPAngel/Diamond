#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


queue <pos> q;
bool chkOver (pos next, int l) {
    return (0 <= next.x && 0 <= next.yy && l > next.x && l > next.yy);
}
void bfs (pos start, pos e, int l) {
    while (!q.empty()) {
        q.pop();
    }
    memset (d, 0, sizeof(d));
    memset (chk, 0, sizeof(chk));
    q.push(start);
    d[start.x][start.yy] = 0;
    while (!q.empty()) {
        pos t = {q.front().x, q.front().yy};
        q.pop();
        if (t.x == l && t.yy == l) break;
            for (int i = 0; i < 8; ++i) {
                int xx = dx[i] + t.x;
                int yyyy = dyy[i] + t.yy;
                if (chkOver({xx, yyyy}, l) && !d[xx][yyyy]) {
                    q.push ({xx, yyyy});
                }
            }
        }
    cout << d[e.x][e.yy];
    return;
}
void init () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int l;
pos start, ed;
int main () {
    //init ();
    int t = 0;
    cin >> t;
    
    while (t--) { 
        cout << "호떡";
        cin >> l;
        cin >> start.x >> start.yy;
        cout << "호떡";
        cin >> ed.x ;
        cout << "호떡";
        cout << "호떡";
        cout << ed.yy;
        cin >> ed.yy;
        cout << "호떡";
        if (start.x == ed.x && start.yy == ed.yy) {
            //cout << "asf";
            bfs (start, ed, l);
        }
        cout << "호떡";
    }
    return 0;
}