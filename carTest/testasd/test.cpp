// #include <assert.h>
// #include <stdio.h>
// int main()
// {
//     int m, n, result;
//     scanf("%d %d", &m, &n);
//     assert(n != 0);  //写作 assert(n) 更加简洁//如果断言成立程序直接退出
//     result = m / n;
//     printf("result = %d\n", result);
//     return 0;
// }

// #include <algorithm>
// #include <cstring>
// #include <iostream>

// using namespace std;

// const int N = 100010;

// bool arr[N];
// int  x[N];

// int n, k, m;

// int main()
// {
//     scanf("%d", &m);
//     while (m--) {
//         scanf("%d%d", &n, &k);
//         int num = k;
//         memset(arr, false, sizeof arr);
//         for (int i = 0; i < k; i++) {
//             scanf("%d", &x[i]);
//             arr[x[i]] = true;
//         }
//         int tt = 1;

//         while (num < n) {
//             for (int i = 0; i < k; i++) {
//                 if (x[i] + tt <= n && !arr[x[i] + tt]) {
//                     num++;
//                 }
//                 if (x[i] - tt > 0) {
//                     if (!arr[x[i] - tt])
//                         num++;
//                 }

//                 arr[x[i] + tt] = true;
//                 if (x[i] - tt > 0)
//                     arr[x[i] - tt] = true;
//             }
//             tt++;
//         }
//         cout << tt << endl;
//     }
//     return 0;
// }

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int              N   = 1010;
const int              INF = 0x3f3f3f3f;
int                    q[N][N];
vector<PII>            temps;
int                    tt, mm = -1;
int                    m;

int main()
{
    scanf("%d", &m);
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            if (sqrt(pow(i, 2) + pow(j, 2)) -
                    (int)sqrt(pow(i, 2) + pow(j, 2)) ==
                0) {
                temps.push_back({i, j});
            }
            if (i == j)
                q[i][j] = 0;
            else
                q[i][j] = INF;
        }
    }
    while (m--) {}
    return 0;
}