#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main () {
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll> > q;
    for (int i = 0; i < n; ++i) {
		int a;
        cin >> a;
        q.push(a);
    } 
    int res = 0;
    while (!(q.empty())) {
        int a = q.top(); q.pop();
        if (q.empty()) break;
        int b = q.top(); q.pop();
        res += (a+b);
        q.push(a+b);
    }
    cout << res;
    return 0;
}