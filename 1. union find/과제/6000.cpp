#include <iostream>
using namespace std;
const int IND = 1e4 * 2 + 5;
int n, coin[IND], res;

void f (int sum, int attempt) {
    if (attempt == n) {
        if (res < sum) 
            res = sum;
        return;
    }
    else {
        if (attempt % 2 == 0) {
            f (sum + coin[attempt], attempt + 1);
            f (sum + coin[attempt] + coin[attempt + 1], attempt + 2);
        }
        else {
            f (sum, attempt + 1);
            f (sum, attempt + 2);
        }
    }
}

int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }
    f (0, 0);
    cout << res;
    return 0;
}