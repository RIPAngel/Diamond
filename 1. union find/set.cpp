#include <iostream>
using namespace std;
const int IND = 1e6 + 10;
int p[IND], n, m;
void r_init () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void init () {
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
}
int find (int x) {
    if (x == p[x]) {
        return x;
    }
    else {
        return p[x] = find(p[x]);
    }
}
int main () {
    r_init();
    cin >> n >> m;
    init ();
    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            int a, b;
            cin >> a >> b;
            int bigA = find (a);
            int bigB = find (b);
            if (bigA != bigB) {
                p[bigA] = bigB;
            }
        }
        else if (type == 1) {
            int a, b;
            cin >> a >> b;
            int bigA = find (a);
            int bigB = find (b);
            if (bigA == bigB) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}