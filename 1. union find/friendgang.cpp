#include <iostream>
using namespace std;
int n, m, p[10001], money[10001], k;
bool chk[10001];

bool moneyCmp (int a, int b) {
    return money[a] < money[b];
}
void setup () {
    for (int i = 1; i <= n; ++i) 
        p[i] = i;
}
void r_find () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int find (int x) {
    return (x == p[x]) ? x : p[x] = find(p[x]);
}
int main () {
    int minMoney = 0;
    r_find();
    cin >> n >> m >> k;
    setup();
    for (int i = 1; i <= n; ++i) 
        cin >> money[i];
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        int aa = find(a), bb = find(b);
        if (moneyCmp (aa, bb)) {
            aa ^= bb ^= aa ^= bb;
        }
        p[aa] = bb;
    }
    for (int i = 1; i <= n; ++i) {
        int xx = find(i);
        if (!(chk[xx])) {
            minMoney += money[xx];
            chk[xx] = true;
        }
    }
    if (minMoney > k)
        cout << "Oh no";
    else 
        cout << minMoney;
    return 0;
}