// #include <iostream>
// #include <cstring>
// #include <cstdio>
// #include <algorithm>
// #include <queue>

// using namespace std;

// priority_queue<int, vector<int>, greater<int>> test;

// const int N = 200003;

// int arr[N], n;

// const int null = 0x3f3f3f3f;

// int find(int x){
//     int idx = (x % N + N) % N;

//     while(arr[idx] != null && arr[idx] != x){
//         idx ++;
//         if(idx >= N) idx = 0;
//     }
//     return idx;
// }

// int main(){
//     scanf("%d", &n);
    
//     memset(arr, 0x3f, sizeof arr);
//     while(n --){
//         char ch[2];
//         int v;
//         scanf("%s%d", ch, &v);
//         if(ch[0] == 'I'){
//             int idx = find(v);
//             arr[idx] = v;
//         } else {
//             int idx = find(v);
//             if(arr[idx] != v) puts("No");
//             else puts("Yes");
//         }
//     }
//     return 0;
// }

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> A, B;

int  n;

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        if(num % 2) B.push(num);
        else A.push(num);
    }
    
    while(!A.empty() || !B.empty()){
        if(!A.empty()) {
            printf("%d ", A.front());
            A.pop();
            printf("%d ", A.front());
            A.pop();
        }
        if(!B.empty()) {
            printf("%d ", B.front());
            B.pop();
        }
    }
    return 0;
}
