#include <iostream>
using namespace std;
int n, dp[69740];
const int DIVIDE = 1e9 + 7;

int main () {
    cin >> n;
	dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int k = n; k >= i; --k) {
            dp[k] += dp[k - i];
			dp[k] = dp[k] % DIVIDE;
		}
    }
    cout << dp[n] % DIVIDE;
    return 0;
}