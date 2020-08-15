#include <bits/stdc++.h>
using namespace std;

struct xu {
	int rank;
	int start;
	int question;
} ry[1000000];

bool srt (const xu &r, const xu &y) {
	if (r.start == y.start) {
		return r.rank < y.rank;
	}
	return r.start < y.start;
}
struct xury{
	bool operator()(const xu &r, const xu &y) {
		return r.rank > y.rank;
	} 
};
int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ry[i].start >> ry[i].question;
		ry[i].rank = i;
	}
	sort (ry, ry + n, srt);
	priority_queue<xu, vector<xu>, xury> q;
    int it = 0, res = 0, i = 0;
    while (i < n) {
        if (q.empty()) {
            it = ry[i].start + ry[i].question;
            i++;
        }
        else {
            xu r_y = q.top(); q.pop();
            int wtwt = it - r_y.start;
            if (res < wtwt) res = wtwt;
            it = it + r_y.question;
        }
        while(i < n) {
            if (ry[i].start <= it) {
                q.push (ry[i]);
                i++;
            }
            else {
                break;
            }
        }
    }
    cout << res;
    return 0;
}