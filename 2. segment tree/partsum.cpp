#include <iostream>
using namespace std;
const int IND = 1e6 * 4 + 100;
int n, m, k, arr[IND];

void bigsur (int idx, int value) {
    arr[idx] = value;
    idx /= 2;
    while (idx > 0) {
        arr[idx] = arr[2 * idx] + arr[2 * idx + 1];
        idx /= 2;
    }
}

int ios14 (int left, int right) {
    int sum = 0;
    while (left <= right) {
        if (left % 2 == 1) {
            sum += arr[left++];
        }
        if (right % 2 == 0) {
            sum += arr[right--];
        }
        left /= 2;
        right /= 2;
    }
    return sum;
}

int main () {
    cin >> n >> m >> k;
    int new_n;
    for (new_n = 1; new_n < n; new_n *= 2);
    for (int i = new_n; i < new_n + n; ++i) {
        cin >> arr[i];
    }
    for (int i = new_n - 1; i >= 1; --i) {
        arr[i] = arr[2 * i] + arr[2 * i + 1];
    }
    int temp = m + k;
    while (temp--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd) {
            bigsur (new_n + a - 1, b);
        }
        else if (cmd == 2) {
            cout << ios14 (new_n + a - 1, new_n + b - 1) << "\n";
        }
    }
    return 0;
}