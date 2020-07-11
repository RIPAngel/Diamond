#include <bits/stdc++.h>
using namespace std;
int n, dp[1111111];

int you_llama (int d) {
    if (d == 0) return 0;
    if (dp[d] != 0) return dp[d];
    if (d < 0) return 1;
    int m = 1e9;
    for (int i = 1; i * i <= d; ++i) {
        m = min (m, you_llama (d - i * i) + 1);
    }
    return dp[d] = m;
}

int main () {
    cin >> n;
    you_llama (n);
    cout << dp[n];
}