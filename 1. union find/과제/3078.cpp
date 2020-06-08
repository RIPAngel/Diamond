#include <iostream>
#include <string>
#include <limits>
using namespace std;
const int IND = 1e5 * 3 + 10;
int n, k, minLength = 20, maxLength = 2;
string x[IND];

int main () {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        if (x[i].size() > maxLength) {
            maxLength = x[i].size();
        }
        if (x[i].size() < minLength) {
            minLength = x[i].size();
        }
    }
    for (int ind = 0; ind < n; ++ind) {
        for (int i = minLength; i <= maxLength; ++i) {
            if (x[ind].size() == i) {
                
            }
        }
    }
    
    cout << maxLength << minLength;
}