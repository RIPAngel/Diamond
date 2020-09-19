#include <bits/stdc++.h>
using namespace std;
vector <int> adj[6974892];
int res[6974892], memo[6974892];
int n, m, visit[6974892];

int dfs (int cur) {
    if (memo[cur] != 0) return memo[cur];
    int sum = 0;
    visit[cur] = true;
    for (int i = 0; i < adj[cur].size(); ++i) {
        int next = adj[cur][i];
        if (!visit[next]) sum += dfs(next);
    }
    memo[cur] = sum;
    return memo[cur];
}
int main () {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    int ma = 0;
    for (int i = 1; i <= n; ++i) {
        memset (visit, 0, sizeof(visit)); dfs(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (ma < memo[i]) ma = memo[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (ma == memo[i]) cout << i << " ";
    }
    return 0;
}