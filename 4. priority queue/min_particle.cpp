#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
using pp = pair<pair<long long, long long>, pair<int, int>>; // dist speed abz rm
vector<pair<pair<long long, long long>, int>> v;             // x v num
struct fgreater
{
    bool operator()(pp l, pp r)
    {
        if (l.ff.ff * r.ff.ss == r.ff.ff * l.ff.ss)
            return v[l.ss.ff].ss > v[r.ss.ff].ss;
        return l.ff.ff * r.ff.ss > r.ff.ff * l.ff.ss;
    }
};
int n;
long long L;
vector<int> exist, nxt, prv, ans;
priority_queue<pp, vector<pp>, fgreater> pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> L >> n;
    v.resize(n);
    exist.resize(n);
    nxt.resize(n);
    prv.resize(n);
    bool valid = false;
    for (int i = 0; i < n; i++)
        cin >> v[i].ff.ff >> v[i].ff.ss, v[i].ss = i + 1, valid = (valid || v[i].ff.ss != v[0].ff.ss);
    if (valid == false)
    {
        cout << "0" << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        nxt[i] = j;
        prv[j] = i;
        exist[i] = true;
        long long dist = v[j].ff.ff - v[i].ff.ff;
        long long speed = v[i].ff.ss - v[j].ff.ss;
        if (speed < 0)
            dist *= -1, speed *= -1;
        if (dist < 0)
            dist += L;
        pq.push({{dist, speed}, {(v[i].ff.ss < v[j].ff.ss ? i : j), (v[i].ff.ss < v[j].ff.ss ? j : i)}});
    }
    while (!pq.empty())
    {
        long long cospeed = pq.top().ff.ss; //approach speed
        int abz = pq.top().ss.ff;           // absorb particle number(sorted)
        int rm = pq.top().ss.ss;            //remain particle number(sorted)
        int newlink;
        pq.pop();
        if (cospeed == 0)
            break;
        if (!exist[abz] || !exist[rm])
            continue;
        if (nxt[abz] == rm)
            prv[rm] = prv[abz], nxt[prv[abz]] = rm, newlink = prv[abz];
        else
            nxt[rm] = nxt[abz], prv[nxt[abz]] = rm, newlink = nxt[abz];
        ans.push_back(v[abz].ss);
        exist[abz] = false;
        long long dist = v[newlink].ff.ff - v[rm].ff.ff;
        long long speed = v[rm].ff.ss - v[newlink].ff.ss;
        if (speed < 0)
            dist *= -1, speed *= -1;
        if (dist < 0)
            dist += L;
        pq.push({{dist, speed}, {(v[newlink].ff.ss < v[rm].ff.ss ? newlink : rm), (v[newlink].ff.ss < v[rm].ff.ss ? rm : newlink)}});
    }
    for (auto i : ans)
        cout << i << " ";
}
