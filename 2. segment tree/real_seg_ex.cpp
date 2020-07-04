#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Tree {
    vector<ll> node;
    ll update (ll node_num, ll s, ll e, ll x, ll value) {
        if (x < s || x > e) return node[node_num];
        if (s == e) return node[node_num] = value;
        ll mid = (s + e) / 2;
        return node[node_num] = update (2 * node_num, s, mid, x, value) + update (2 * node_num + 1, mid + 1, e, x, value);
    }
    ll query (ll node_num, ll s, ll e, ll l, ll r) {
        if (e < l || r < s) return 0;
        if (l <= s && e <= r) return node[node_num];
        ll mid = (s + e) / 2;
        return query (2 * node_num, s, mid, l, r) + query (2 * node_num + 1, mid + 1, e, l, r);
    }
}node;

int main () {
    int n, m, k;
    cin >> n >> m >> k;
    node.node.resize (4 * n);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        node.update(1, 1, n, i, a);
    }
    for (int i = 0; i < m + k; ++i) {
        int type, v1, v2;
        cin >> type >> v1 >> v2;
        if (type == 1) {
            node.update(1, 1, n, v1, v2);
        }
        else if (type == 2) {
            cout << node.query (1, 1, n, v1, v2) << endl;
        }
    }
    return 0;
}