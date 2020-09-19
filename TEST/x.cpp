#include <bits/stdc++.h>
using namespace std;
int triangle[15][15];

void bfs () {
    int x, y;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (triangle[i][j]) {
                x = i, y = j;
                break;
            }
        }    
    }
    queue <pair <int, int> > q;
    q.push({x, y});
    while (!(q.empty())) {
        
    }

}
int main () {
    for (int i = 0 ; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            scanf ("%1d", &triangle[i][j]);
        }
    }
    return 0;
}

