#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int IND = 1e5 * 5 + 15;
typedef struct graph {
    int horse;
    int from;
    int to;
}graph;
vector <graph> d;
int p[IND], n, m;
void init () {
    for (int i = 1; i <= m; ++i) {
        p[i] = i;
    }
}
int find (int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}
void merge ()