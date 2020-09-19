#include <bits/stdc++.h>
using namespace std;
vector<int> ntadj[405];
bool visit[405];
queue<int> q;
int n, m;
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        ntadj[a].push_back(b);
        ntadj[b].push_back(a);
    }
    int maxres = 1 << n;
    q.push(1);
    visit[1] = true;
    while (!q.empty()) {
        int front = q.front(); q.pop();
        for (int i = 0; i < ntadj[front].size(); ++i) {
            int next = ntadj[front][i];
            if (!visit[next]) {
                q.push(next);
                visit[next] = true;
                maxres--;
            }
        }
    }
    cout << maxres;
    return 0;
}