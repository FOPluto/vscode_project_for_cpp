#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int num = 0;
int ans = 0;
int dp[110];

int run(int n)
{
    if (n <= 1) {
        return 1;
    }

    if (num == 2) {
        num = 0;
        if (dp[n - 1] > 0) {
            return dp[n - 1];
        }
        else {
            dp[n - 1] += run(n - 1);
            return dp[n - 1];
        }
    }
    else {
        num++;
        if (dp[n - 2] > 0) {
            dp[n] += dp[n - 2];
        }
        else {
            dp[n] += run(n - 2);
        }

        num = 0;
        if (dp[n - 1] > 0) {
            dp[n] += dp[n - 1];
        }
        else {
            dp[n] += run(n - 1);
        }

        return dp[n];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    ans = run(n);
    printf("%d\n", ans);
    return 0;
}