#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Tree {
    vector<ll> node_max;
    vector<ll> node_min;
    ll update_min (ll node_num, ll s, ll e, ll x, ll value) {
        if (x < s || x > e) return node_min[node_num];
        if (s == e) return node_min[node_num] = value;
        ll mid = (s + e) / 2;
        return node_min[node_num] = min(update_min (2 * node_num, s, mid, x, value), update_min  (2 * node_num + 1, mid + 1, e, x, value));
    }
    ll update_max (ll node_num, ll s, ll e, ll x, ll value) {
        if (x < s || x > e) return node_max[node_num];
        if (s == e) return node_max[node_num] = value;
        ll mid = (s + e) / 2;
        return node_max[node_num] = max(update_max (2 * node_num, s, mid, x, value), update_max (2 * node_num + 1, mid + 1, e, x, value));
    }
    ll query_min (ll node_num, ll s, ll e, ll l, ll r) {
        if (e < l || r < s) return 0;
        if (l <= s && e <= r) return node_min[node_num];
        ll mid = (s + e) / 2;
        return min (query_min (2 * node_num, s, mid, l, r), query_min (2 * node_num + 1, mid + 1, e, l, r));
    }
    ll query_max (ll node_num, ll s, ll e, ll l, ll r) {
        if (e < l || r < s) return 0;
        if (l <= s && e <= r) return node_max[node_num];
        ll mid = (s + e) / 2;
        return max (query_max (2 * node_num, s, mid, l, r), query_max (2 * node_num + 1, mid + 1, e, l, r));
    }
}node;

int main () {
    int n, m;
    cin >> n >> m;
    node.node_min.resize(4*n);
    node.node_max.resize(4*n);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        node.update_min(1, 1, n, i, a);
        node.update_max(1, 1, n, i, a);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << node.query_min(1, 1, n, a, b) << " " << node.query_max(1, 1, n, a, b) << "\n";
    }
    return 0;
}