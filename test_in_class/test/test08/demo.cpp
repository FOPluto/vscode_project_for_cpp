#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 1010;

using namespace std;

int arr[N][N];
int dp[N][N];
int n;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1;i <= n;i++){
        dp[n][i] = arr[n][i];
    }

    for(int i = n - 1;i >= 1;i--){
        for(int j = 1;j <= i;j++){
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j];
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
    puts("");
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            printf("%d ", dp[i][j]);
        }
        puts("");
    }

    return 0;
}