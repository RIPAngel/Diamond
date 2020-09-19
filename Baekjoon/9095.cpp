#include <bits/stdc++.h>
using namespace std;
int main () {
    int n = 0; cin >> n;
    while (n--) {
        int k = 0; 
        cin >> k;
        int dp[15] = {};
        dp[1] = 1; dp[2] = 2; dp[3] = 4;
        for (int i = 4; i <= k; ++i) {
            dp[i] = dp [i - 1] + dp [i - 2] + dp [i - 3];
        }
        cout << dp[k] << "\n";
    }
    return 0;
}