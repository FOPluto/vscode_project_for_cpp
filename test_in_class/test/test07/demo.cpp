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
    int mid = arr[l + r >> 1];
    while(i < j){
        do i ++; while(arr[i] > mid);
        do j --; while(arr[j] < mid);
        if(i < j) swap(arr[i], arr[j]);
    }
    if(j - l + 1 >= k) return qsort(arr, l, j, k);
    else return qsort(arr, j + 1, r, k - (j - l + 1));   
}

int main(){
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    int res = qsort(arr, 0, n - 1, k);
    printf("%d\n", res);
    return 0;
}