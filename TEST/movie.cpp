#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;const int IND=5*1e5+6;pair<int,int>m[IND];int n,jojo,minn[IND];bool cmp (pair<int,int>a,pair<int,int>b){return a.se<b.se;}int main(){cin>>n;for(int i=0;i<n;++i){cin>>m[i].fi>>m[i].se;}sort(m,m+n,cmp);minn[n-1]=m[n-1].first;for(int i=n-2;i>=0;--i){minn[i]=min(m[i].first,minn[i+1]);}long long sum=0;for(int i=0;i<n;++i){if(m[jojo].se-m[jojo].fi<m[i].se-m[i].fi){jojo=i;}sum+=m[i].se;cout<<min(sum-m[jojo].se+m[jojo].first,sum-m[jojo].se+minn[i])<<"\n";}return 0;}