#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1000010;

int t;
int l, r;

bool st[N];

int primer[N], cnt;

void getPrimes() {
    memset(st, 0, sizeof(st));
    for (int i = 2; i < N; i++) {
        if (!st[i]) {
            primer[cnt++] = i;
            for (int j = i + i; j < N; j += i) {
                st[j] = true;
            }
        }
    }
}

int main() {
    getPrimes();

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &l, &r);
        if ((1 + r >> 1) > l) {
            puts("Yes");
            continue;
        }

        bool exists = false;

        for (int x = l; x <= r; x++) {
            int val = x - x % primer[x - l];
            if (val >= l && 2 * (x - val) >= primer[x - l]) {
                exists = true;
                break;
            }
        }

        if (exists) {
            puts("Yes");
        } else {
            puts("No");
        }
    }

    return 0;
}