#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> ans;

const int N = 3010;

int arr[N][N], n, dp[N][N];

int main(){
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){//输入
        for(int j = 1;j <= i;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 1;i <= n;i++){//更新最底下的位置
        dp[n][i] = arr[n][i];
    }
    
    
    for(int i = n - 1;i >= 1;i--){
        for(int j = 1;j <= i;j++){
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j];
        }//每一次取下一层的最大距离
    }
    printf("%d", dp[1][1]);
    printf("[");
    //下面就是回溯回去了
    printf("%d", arr[1][1]);
    for (int i = 2, j = 1; i <= n; ++i)
    {
        int node = dp[i - 1][j] - arr[i - 1][j]; //计算出来这个点应该是多少
        if (node == dp[i][j + 1]) ++j; //然后依次比较即可
        cout << "-->" << arr[i][j];
    }
    printf("]");
    return 0;
} 
