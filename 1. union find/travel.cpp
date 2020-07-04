#include <iostream>
using namespace std;
int n, m, p[205], travel[1005];
void setup () {
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
}
int find (int x) {
    if (x == p[x]) 
        return x;
    else 
        return p[x] = find(p[x]);
}
void init (int x, int y) {
    int xx = find(x);
    int yy = find(y);
    if (xx != yy)
        p[xx] = yy;
}
void r_init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main () {
    r_init();
    cin >> n >> m;
    setup();
    for (int i = 1;  i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int a;
            cin >> a;
            if (a) {
                init(i, j);
            }
        }
    }
    int temp;
    cin >> temp;
    temp = find(temp);
    for (int i = 1; i < m; ++i) {
        int a;
        cin >> a;
        if (find(a) != temp) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}