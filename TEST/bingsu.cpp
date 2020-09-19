#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int main () {
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll> > q;
    for (int i = 0; i < n; ++i) {
		ll a;
        cin >> a;
        q.push(a);
    } 
    ll res = 0;
    while (!(q.empty())) {
        ll a = q.top(); q.pop();
        if(q.empty()) break;
        ll b = q.top(); q.pop();
        res += (a+b);
        q.push(a+b);
    }
    cout << res;
    return 0;
}