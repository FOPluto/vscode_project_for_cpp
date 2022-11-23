// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// typedef unsigned long long LL;

// LL        k;
// int       n;
// const int N = 100010;

// int a[N], b[N];
// LL  res;

// LL calc(int m)
// {
//     LL ans = 0;
//     for (int i = 1; i <= n; i++) {
//         ans += min(a[i], m);
//     }
//     return ans;
// }

// int main()
// {
//     scanf("%d%lld", &n, &k);

//     for (int i = 1; i <= n; i++) {
//         scanf("%d", &a[i]);
//         res += a[i];
//     }
//     if (res < k) {
//         printf("-1\n");
//         return 0;
//     }
//     int l = 0, r = 1e9;
//     while (l + 1 < r) {//有点迷
//         int m = l + r >> 1;
//         if (calc(m) <= k)
//             l = m;
//         else
//             r = m;
//     }

//     k -= calc(l);
//     int cnt = 0;
//     for (int i = 1; i <= n; i++) {
//         if (a[i] > l)
//             b[++cnt] = i;
//     }
//     for (int i = k + 1; i <= cnt; i++) {
//         printf("%d ", b[i]);
//     }
//     for (int i = 1; i <= k; i++) {
//         if (a[b[i]] != l + 1)
//             printf("%d ", b[i]);
//     }
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    return 0;
}