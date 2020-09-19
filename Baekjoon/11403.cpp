#include <bits/stdc++.h>
using namespace std;
vector<int> adj[105];
int n;

bool dfs (int cur, int dest) {
    if (cur == dest) return true;
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int a; cin >> a;
            if (a) adj[i].push_back(j);
        }
    }
}