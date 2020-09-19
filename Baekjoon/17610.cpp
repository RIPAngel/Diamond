#include <iostream>
using namespace std;
int k, g[15], res, sum;
bool check[10000000];

void sans (int value, int att) {
    if (att < 0) return;
    if (att == 0) {
        if (value > 0) check[value] = true;
        return;
    }
    sans (value, att - 1);
    sans (value + g[att - 1], att - 1);
    sans (value - g[att - 1], att - 1);

}

int main () {
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> g[i];
        sum += g[i];
    }
    sans (0, k);
    for (int i = 1; i <= sum; ++i) {
        if (!(check[i])) res++;
    }
    cout << res;
    return 0;
}