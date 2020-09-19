#include <bits/stdc++.h>
using namespace std;

int solve () {
    int v, e;
    vector<int> adj[200005];
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


}

int main () {
    int n = 0;
    cin >> n;
    while (n--) solve();
    return 0;
}