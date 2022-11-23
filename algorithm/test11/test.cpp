//  #include <algorithm>
//  #include <cstdio>
//  #include <cstring>
// #include <iostream>
// #include <thread>

// using namespace std;

// const int               N = 500010;
// typedef pair<int, bool> PII;

// int temp[N];
// PII arr[N];
// int brr[N];
// int ans[N];
// int cnt;
// int n;

// int main()
// {
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i].first);
//         brr[i] = arr[i].first;
//     }

//     sort(brr, brr + n - 1);
//     int min = brr[0], max = brr[n - 1];

//     for (int i = 0; i < n; i++) {
//         temp[arr[i].first - min]++;
//         if (temp[arr[i].first - min] >= 2)
//             arr[i].second = true;
//     }

//     for (int i = 0; i <= N; i++) {
//         if (!temp[i])
//             brr[cnt++] = i;
//     }
//     int idx = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i].second)
//             arr[i].first = brr[idx++] + min;
//     }
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i].first);
//     }
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 500010;

int arr[N];
int temp[N];
int n, idx;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int Min = 0x3f3f3f3f;
    for (int i = 0; i < n; i++)
        if (arr[i] < Min)
            Min = arr[i];
    int min = arr[0];

    for (int i = 0; i < n; i++) {
        if (min > arr[i])
            min = arr[i];
        idx = min - Min;
        temp[arr[i] - Min]++;
        if (temp[arr[i] - Min] >= 2) {
            while (temp[idx])
                idx++;

            arr[i] = idx + Min;
            temp[idx]++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
