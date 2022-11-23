#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1010;
int       arr[N], n;
int       t[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        t[i] = arr[i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[j] > arr[i])
                arr[j] = max(arr[j], arr[i] + t[j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, arr[i]);
    }
    cout << ans;
    return 0;
}