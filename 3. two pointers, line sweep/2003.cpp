#include <iostream>
using namespace std;
const int XX = 1e6;
int n, m, a[XX];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int sum = 0, cnt = 1, res = 0;
    for (int it = 1; it <= n; ++it) {
        sum += a[it];
        while (sum > m) {
            sum -= a[cnt++];
        }
        if (sum == m) {
            res++;
        }
    }
    cout << res;
    return 0;
}