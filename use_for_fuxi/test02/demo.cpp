#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200003;

int arr[N];

const int null = 0x3f3f3f3f;

int n;

int find(int t){
    int k = (t % N + N) % N;
    while(arr[k] != t && arr[k] != null){
        k ++;
        if(k >= N) k = 0;
    }
    
    return k;
}

int main(){
    
    scanf("%d", &n);
    
    memset(arr, 0x3f, sizeof arr);
    for(int i = 0;i < n;i++){
        char ch[2];
        int num;
        scanf("%s%d", ch, &num);
        if(ch[0] == 'I') {
            int idx = find(num);
            arr[idx] = num;
        } else {
            int idx = find(num);
            if(arr[idx] == null) puts("No");
            else puts("Yes");
        }
    }
    
    return 0;
}