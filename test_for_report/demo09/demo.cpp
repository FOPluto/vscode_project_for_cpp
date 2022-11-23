#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 10000010;

int arr[N], n, k;

int qsort(int arr[], int l, int r, int k){
    if(l >= r) return arr[l];
    int i = l - 1, j = r + 1;
    int mid = arr[l + r >> 1];  // 去中间值
    while(i < j){
        do i ++; while(arr[i] > mid);
        do j --; while(arr[j] < mid);
        if(i < j) swap(arr[i], arr[j]);
    }
    // 如果当前的中间相对位置是位于k之后的话
    if(j - l + 1 >= k) return qsort(arr, l, j, k); 
    // 如果当前的中间相对位置是位于k之前的话
    else return qsort(arr, j + 1, r, k - (j - l + 1));   
}

int main(){
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        scanf("%d", &arr[i]);
    }
//     sort(arr, arr + n, [](const int &a, const int &b){  //也可以直接进行排序，找第k-1个数
//         return a > b;
//     });
    
    cout << qsort(arr, 0, n - 1, k);
    
//     cout << arr[k - 1] << endl;
    return 0;
}