#include <iostream>
using namespace std;
const int IND1 = 1e3 * 2 + 5;
int n, m, arr[IND1], dp[IND1][IND1];
void init () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool dynamic (int s, int e) {
    if (s >= e) {
        return true;
    }
    if (dp[s][e] != -1) {
        return dp[s][e];
    }
    if (arr[s] == arr[e]) {
        return dp[s][e] = dynamic (s + 1, e - 1);
    }
    else {
        return false;
    }
}
int main () {
    init();
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    memset (dp, -1, sizeof(dp));
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int left, right;
        cin >> left >> right;
        cout << dynamic (left, right);
    }
    return 0;
}