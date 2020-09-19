#include <bits/stdc++.h>
using namespace std;
const int IND = 405;
int n, m, p[IND];
int find (int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}
void setup () {
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
}
int init (int a, int b) {
    int aa = find(a);
    int bb = find(b);
    if (aa != bb) p[aa] = bb;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        init (a, b);
    }
    int maxres = 1 << n;
    vector<int> it;
    for (int i = n; i >= 1; --i) {
        it.push_back(i);
    }
    
}