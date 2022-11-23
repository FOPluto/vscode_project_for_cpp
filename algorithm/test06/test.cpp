#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1100;

typedef unsigned long long LL;
LL                         arr[N][3];

int main()
{
    int n = 0;
    scanf("%d", &n);
    arr[1][0]++;
    arr[2][1]++;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j <= 2; j++) {
            LL flag = arr[i][j];
            if (flag && j < 2) {
                arr[i + 2][j + 1] += flag;
                arr[i + 1][0] += flag;
            }
            if (flag && j == 2) {
                arr[i + 1][0] += flag;
            }
        }
    }
    cout << arr[n][0] + arr[n][1] + arr[n][2] << endl;
    return 0;
}