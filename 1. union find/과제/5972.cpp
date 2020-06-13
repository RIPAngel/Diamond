#include <iostream>
using namespace std;
const int IND = 1e4 * 5 + 15;
bool chk[IND];
int n, m, horse[IND];
vector <int> data[IND];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b >> horse[i];
        data[i].push_back (a);
        data[i].push_back (b);
        data[b].push_back (i);
        data[a].push_bacl (i);
    }
}