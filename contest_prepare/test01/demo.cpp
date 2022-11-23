#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>


using namespace std;

const int N = 100010;

int arr[N];

int n, m;

int upper_bound(int arr[], int l, int r, int x){
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(arr[mid] > x) r = mid - 1;
        else l = mid;
    }
    if(arr[l] != x) return -1;
    return r;
}

int lower_bound(int arr[], int l, int r, int x){
    while(l < r){
        int mid = l + r >> 1;
        if(arr[mid] < x) l = mid + 1;
        else r = mid;
    }
    if(arr[r] != x) return -1;
    return l;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++){
        scanf("%d", &arr[i]);
    }
    while(m--){
        int num = 0;
        scanf("%d", &num);
        int l = 0, r = n - 1;
        int left = lower_bound(arr, l, r, num);
        int right = upper_bound(arr, l, r, num);
        printf("%d %d\n", left, right);
    }
    return 0;
}
