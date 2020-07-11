#include <iostream>
using namespace std;
int D[6974], arr[6974], res;

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        int ma = 0;
        for (int j = 1; j <= i; ++j) {
            if (arr[j] < arr[i] && ma < D[j]) {
                ma = D[j];
                res += arr[j];
            }
        }
        D[i] = ma + 1;
    }
    cout << res;
    return 0;
}