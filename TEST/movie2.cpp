#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
const int IND = 5 * 1e5 + 10;
pp m[IND];
int n;
bool cmp (pp a, pp b) { 
    return a.second < b.second; 
}
int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i].first >> m[i].second;
    }
    sort (m, m+n, cmp);
}