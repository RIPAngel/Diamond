#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct heap {
    int arr [1 << 17];
    int cnt = 0;
    int top () {
        if (empty()) cout << "ㅂㅅ";
        else {
            return arr[1];
        }
    }

    void push (int x) {
        arr[++cnt] = x;
		int cur = cnt;
        while (cur > 1) {
           
            if (arr[par] > arr[cur]) {
                arr[par] ^= arr[cur] ^= arr[par] ^= arr[cur];
            }
			else {
				break;
			}
        }
    }
    void pop () {
        arr[1] = arr[cnt];
        arr[cnt--] = NULL;
        int cur = 1;
        while (1) {
            int l = arr[cur * 2];
            int r = arr[cur * 2 + 1];
            if (arr[cur] > arr[cur * 2] && arr[cur] > arr[cur * 2 + 1]) break;
            if (l > r) {
                arr[cur] ^= arr[cur * 2] ^= arr[cur] ^= arr[cur * 2];
                cur = cur * 2;
            }
            else {
                arr[cur] ^= arr[cur * 2] ^= arr[cur] ^= arr[cur * 2];
                cur = cur * 2 + 1;
            }
        }
    }
    bool empty () {
        if (cnt == 0) return true;
        else return false;
    }
    int size () {
        return cnt;
    }
}hp;

int main () {
    hp.push(1); hp.push(2); hp.push(7); hp.push(4); hp.push(3); hp.push(9); hp.push(4);
    cout << hp.top() << endl;
    hp.pop();
    cout << hp.top() << endl;
    hp.pop();
    cout << hp.top() << endl;
    hp.pop();
    cout << hp.top() << endl;
    hp.pop();
    cout << hp.top() << endl;
    hp.pop();
    return 0;
}
