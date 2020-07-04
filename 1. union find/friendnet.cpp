#include <iostream>

using namespace std;
const int IND = 1e5 + 5;
int p[IND], sz[IND];

int find (int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}
void r_find () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
