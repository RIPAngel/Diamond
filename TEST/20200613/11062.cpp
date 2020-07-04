#include <iostream>
#define truE 1
#define falsE 0
using namespace std;
int testcase, arr[1001], dp[2][1001][1001];
int gang (int t, int l, int r) {
    if (l == r) {
        if (t == 0) {
            return arr[l];
        }
        else {
            return 0;
        }
    }
    if (dp[t][l][r] != -1) return dp[t][l][r];
    if (t == 0) {
        dp[t][l][r] = max(gang(t ^ 1, l + 1, r) + arr[l], gang (t ^ 1, l, r - 1) + arr[r]);
    }
    else {
        dp[t][l][r] = min(gang(t ^ 1, l + 1, r), gang (t ^ 1, l, r - 1));
    }
    return dp[t][l][r];
}
int main () {
    cin >> testcase;
    while (testcase--) {
        int n;
        memset(arr, 0, sizeof(arr));
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << gang (0, 0, (n - 1)) << "\n";
    }
}