#include <iostream>
#define MOD 1000000007
using namespace std;
int dp[1000004], n;

int multiple (int x, int y) {
	if (y == 0) return 1;
    if (y == 1) return x % MOD;
    if (y % 2 == 1) {
        int sib = multiple(x, y - 1) % MOD;
        return ((sib % MOD) * (x % MOD)) % MOD;
    }
    else {
        int al = multiple (x, y/2) % MOD;
        return (al * al) % MOD;
    }
}
int main () {
	cin >> n;
	cout << multiple (2, n - 1);
	return 0;
}