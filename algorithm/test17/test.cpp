// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// const int N = 100;
// long long dp[N];
// int       main()
// {
//     int       t, m, i;
//     long long n;
//     long long mod = 1e9 + 7;
//     for (i = 0; i < 10; i++)
//         dp[i] = 1;
//     for (i = 10; i < N; i++) {
//         dp[i] = dp[i - 10] + dp[i - 9];
//         while (dp[i] >= mod)
//             dp[i] -= mod;
//     }
//     scanf("%d", &t);
//     while (t--) {
//         long long ans = 0;
//         scanf("%lld%d", &n, &m);
//         for (; n; n /= 10) {
//             ans = ans + dp[m + n % 10];
//             while (ans >= mod)
//                 ans -= mod;
//         }
//         printf("%lld\n", ans);
//     }
//     return 0;
// }

// #include <cstdio>
// #include <iostream>
// using namespace std;

// enum class MyClass : char { Ceaf = 'A', aevaadx, affed };

// enum class MyClas : int { Ceaf = 0, afvdsdvf, adv };
// int main()
// {
//     int m = (int)MyClass::Ceaf;
//     cout << m << endl;
//     return 0;
// }
