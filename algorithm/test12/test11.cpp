// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <set>

// using namespace std;

// int                 n;
// set<pair<int, int>> c;

// inline void insert(int l, int r)
// {
//     if (l > r)
//         return;
//     c.insert(make_pair(r, l));
// }

// int main()
// {
//     scanf("%d", &n);
//     c.insert(make_pair(2e9, 1));
//     for (int i = 1; i <= n; i++) {
//         int x;
//         scanf("%d", &x);
//         auto itr = c.lower_bound(make_pair(x, 99));
//         if (itr->second <= x) {
//             printf("%d", x);
//             insert(itr->second, x - 1);
//             insert(x + 1, itr->first);
//             c.erase(itr);
//         }
//         else {
//             printf("%d", itr->second);
//             insert(itr->second + 1, itr->first);
//             c.erase(itr);
//         }
//     }
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <set>

// using namespace std;

// int                 n;
// set<pair<int, int>> c;

// inline void insert(int l, int r)
// {
//     if (l > r)
//         return;
//     c.insert(make_pair(r, l));
// }

// int main()
// {
//     scanf("%d", &n);
//     c.insert(make_pair(2e9, 1));

//     for (int i = 1; i <= n; i++) {
//         int x;
//         scanf("%d", &x);
//         auto t = c.lower_bound(make_pair(x, 0));
//         if (t->second <= x) {
//             printf("%d ", x);
//             insert(t->second, x - 1);
//             insert(x + 1, t->first);
//             c.erase(t);
//         }
//         else {
//             printf("%d ", t->second);
//             insert(t->second + 1, t->first);
//             c.erase(t);
//         }
//     }
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

int                 n;
set<pair<int, int>> c;

inline void insert(int l, int r)
{
    if (l > r)
        return;
    c.insert(make_pair(r, l));
}

int main()
{
    scanf("%d", &n);
    c.insert(make_pair(2e9, 1));

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        auto t = c.lower_bound(make_pair(x, 0));
        if (t->second <= x) {
            printf("%d ", x);
            insert(t->second, x - 1);
            insert(x + 1, t->first);
            c.erase(t);
        }
        else {
            printf("%d ", t->second);
            insert(t->second + 1, t->first);
            c.erase(t);
        }
    }
    return 0;
}