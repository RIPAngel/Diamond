#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
vector<int> p[25];
int n, k, res;
string name[300010];

int main () {
    int lengthMin = 20, lengthMax = 2;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> name[i];
        p[name[i].size()].push_back (i);
        if (name[i].size() < lengthMin) {
            lengthMin = name[i].size();
        }
        if (name[i].size() > lengthMax) {
            lengthMax = name[i].size();
        }
    }
    for (int i = lengthMin; i <= lengthMax; ++i) {
        if (!p[i].size()) {
            continue;
        }
        else {
            for (int left = 0, right = (p[i].size() - 1); left <= right; left++, right--) {
                //printf ("%d %d %d\n", i, left, right);
                if (p[i][right] - p[i][left] <= k) {
                    res++;
                }
            }
        }
    }
    cout << res;
}