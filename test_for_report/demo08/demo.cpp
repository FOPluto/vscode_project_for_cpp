#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N];
int n;
int num[N];

int main(){
    cin >> n;
    
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) num[i] = 1;
    
// 从前面往后面遍历
    for(int i = 0;i < n - 1;i++){
        if(num[i + 1] <= num[i] && a[i + 1] > a[i]) num[i + 1] = num[i] + 1;
}
// 从后面往前面遍历
    for(int i = n - 1;i > 0;i--){
        if(num[i - 1] <= num[i] && a[i - 1] > a[i]) num[i - 1] = num[i] + 1;
    }
    long long ans = 0;   //这里不开long long是可能爆数据的
    for(int i = 0;i < n;i++) ans += num[i]; // 输出结果
    cout << ans << endl;
    return 0;
}
