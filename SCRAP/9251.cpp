#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string a, b;
int len_a, len_b, dp[1001][1001];

int run (int ap, int bp) {
    if (dp[ap][bp] != 0) {
        return dp[ap][bp];
    }
    if (ap == len_a || bp == len_b) {
        return 0;
    }
    if (a[ap] == b[bp]) {
        return dp[ap][bp] = 1 + run (ap + 1, bp + 1);
    }
    return dp[ap][bp] = max(run(ap + 1, bp), run(ap, bp+1));
}
int main () {
    cin >> a >> b;
    len_a = a.size();
    len_b = b.size();
    int res = run (0, 0);
    cout << res;
    return 0;
}
