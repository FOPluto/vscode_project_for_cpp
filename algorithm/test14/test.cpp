// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <unordered_map>

// using namespace std;

// unordered_map<int, int> m;
// int                     n;
// const int               mod = 1e9 + 7;

// int main()
// {
//     scanf("%d", &n);
//     while (n--) {
//         int x;
//         scanf("%d", &x);
//         for (int i = 2; i <= x / i; i++) {
//             while (x % i == 0) {
//                 m[i]++;
//                 x /= i;
//             }
//         }
//         if (x > 1)
//             m[x]++;
//     }
//     int num = 1;
//     for (auto t : m)
//     printf("%d\n", num);
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7;

unordered_map<int, int> m;
int                     n;

int main()
{
    scanf("%d", &n);
    while (n--) {
        int x = 0;
        scanf("%d", &x);
        for (int i = 2; i <= i / ; i++) {
            while (x % i == 0) {
                x /= i;
                m[i]++;
            }
        }
        if (x > 1)
            m[x]++;
    }
    long long ans, num;

    for (auto t : m) {
        long long a = t.first, b = t.second;
        while (b--)
            num = num * (a + 1) % mod;

        ans = ans * num % mod;
    }
    return 0;
}

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int cacu(int a, int b)
{
    return b ? cacu(b, a % b) : a;
}

int main()
{
    int m;
    scanf("%d", &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        cout << cacu(a, b) << endl;
    }
    return 0;
}