// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// const int N = 110;
// const int mod = 1e9 + 7;
// int       ans[N][N];
// int       arr[N][N];

// int main()
// {
//     int n;
//     ans[1][1]++;
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             scanf("%d", &arr[i][j]);
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (!arr[i][j])
//                 ans[i][j] = 0;
//             else
//                 ans[i][j] += ans[i - 1][j] + ans[i][j - 1];
//                 ans[i][j] %= mod;
//         }
//     }
//     printf("%d", ans[n][n]);
//     return 0;
// }