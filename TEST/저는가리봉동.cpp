#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> nde[405];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int a, b; cin >> a >> b;
        nde[a].push_back(b);
    }
    int maxres = 1 << n;
    
}