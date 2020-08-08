#include <bits/stdc++.h>
using namespace std;
const int XX = 6974;
int t, a[XX], n, b[XX], m;

void __init__ () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main () {
    __init__();
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> b[i];
    int sum = 0, cnt1 = 0, cnt2 = 0, res = 0;
    for (int it1 = 0; it1 < n; ++it1) {
        for (int it2 = 0; it2 < m; ++it2) {
            sum += a[it1];
            sum += b[it2];
            while (sum > t) {
                sum -= a[cnt1++];
                sum -= b[cnt2++];
            }
            if (sum == t) res++;
        }
    }
    cout << res;
    return 0;
}

//#CHARTday > table > tbody > tr:nth-child(1) > th > p > a
//#frm > div > table > tbody > tr:nth-child(1) > td:nth-child(4) > div > div > div.ellipsis.rank01 > span > a

