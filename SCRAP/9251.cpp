#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1005][1005];
string a, b;

int main () {
    cin >> a >> b;
    int la = a.size(), lb = b.size();
    for (int i = 1; i <= la; ++i) {
        for (int j = 1; j <= lb; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[la][lb];
    return 0;
}