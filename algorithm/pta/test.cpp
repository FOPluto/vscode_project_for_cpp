// #include <algorithm>
// #include <cstdio>
// #include <iostream>

// using namespace std;

// const int N = 10010;
// int       arr[N];
// int       n, x;

// int main()
// {
//     scanf("%d%d", &n, &x);
//     int temp = -10000;
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//         if (i) {
//             if(arr[i] <= arr[i - 1]){
//                 cout << "Invalid Value" << endl;
//                 return 0;
//             }
//         }
//     }
//     int l = 0, r = n - 1;
//     while (l < r) {
//         int mid = l + r + 1 >> 1;
//         printf("[%d,%d][%d]", l, r, mid);
//         if (arr[mid] <= x)
//             l = mid;
//         else
//             r = mid - 1;
//     }
//     if (arr[l] != x)
//         cout << "Not Found";
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <iostream>

// using namespace std;

// const int N = 10010;
// int       arr[N];
// int       n, x;

// int main()
// {
//     bool tt = false;
//     scanf("%d%d", &n, &x);
//     int temp = -10000;
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//         if (i) {
//             if(arr[i] <= arr[i - 1]){
//                 tt = true;
//             }
//         }
//     }
//     if(tt){
//         cout << "Invalid Value" << endl;
//         return 0;
//     }
//     int l = 0, r = n - 1;
//     while (l <= r) {
//         int mid = l + r >> 1;
//         printf("[%d,%d][%d]\n", l, r, mid);
//         if(arr[mid] > x) r = mid - 1;
//         else if(arr[mid] < x) l = mid + 1;
//         else {
//             r = l = mid;
//             break;
//         }
//     }
//     if (arr[l] != x)
//         cout << "Not Found" << endl;
//     else cout << l << endl;
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;
// int  n;
// char c[10100];
// int  main()
// {
//     scanf("%s", c);
//     int i = 0;
//     while (c[i++] != '\0')
//         ;
//     sort(c, c + i - 1);
//     for (int j = 0; j < i; j++)
//         cout << c[j];
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>

// using namespace std;

// int main()
// {
//     int arr[4][4];
//     for(int i = 0;i < 3;i++)
//         for(int j = 0;j < 3;j++)
//             scanf("%d", &arr[i][j]);
//     for(int i = 0;i < 3;i++){
//         if(i) puts("");
//         for(int j = 0;j < 3;j++){
//             printf("%d ", arr[j][i]);
//         }
//     }
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// const int N = 1010;
// char      input[N];
// char      arr[N][N];

// int main()
// {
//     int n      = 0;
//     int len    = 0;
//     int length = 0;
//     cin >> n;
//     cin.get();
//     cin.getline(input, 30);
//     while (input[length++] != '\0')
//         ;
//     for (int i = 0; i < length / n + 1; i++) {
//         for (int j = 0; j < n; j++) {
//             arr[i][j] = input[len++];
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (i)
//             puts("");
//         for (int j = length / n; j >= 0; j--) {
//             printf("%c", arr[j][i]);
//         }
//     }
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <iostream>

// using namespace std;

// int n;
// int main()
// {
//     char input[1010];
//     char output[1010][1010];
//     cin >> n;
//     getchar();
//     char ch;
//     int  len = 0;
//     while ((ch = getchar()) != '\n') {
//         output[len / n][len % n] = ch;
//         len++;
//     }
//     for (int i = 0; i < n; i++) {
//         if (i)
//             puts("");
//         for (int j = len / n; j >= 0; j--) {
//             printf("%c", output[j][i]);
//         }
//     }
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;
// int arr[10010];

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     int temp = 0;
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     for (int i = 0; i < n; i++) {
//         if (temp++ > k) {
//             for (int j = 0; j < n; j++) {
//                 if (j)
//                     printf(" ");
//                 printf("%d", arr[j]);
//             }
//             return 0;
//         }
//         int mm = i;
//         for (int j = i; j < n; j++) {
//             if (arr[mm] > arr[j])
//                 mm = j;
//         }
//         swap(arr[mm], arr[i]);
//     }

//     for (int j = 0; j < n; j++) {
//         if (j)
//             printf(" ");
//         printf("%d", arr[j]);
//     }
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <iostream>

// using namespace std;

// const int N = 10010;
// int       arr[N];

// int main()
// {
//     int ch;
//     int len = 0;
//     while (scanf("%d", &ch) != EOF)
//         arr[len++] = ch;
//     sort(arr, arr + len - 1);
//     for (int i = 0; i < len; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <iostream>

// using namespace std;

// const int N = 10010;
// int       arr[N];
// int       n;

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j + 1] < arr[j])
//                 swap(arr[j + 1], arr[j]);
//         }
//         for (int j = 0; j < n; j++)
//             printf("%d ", arr[j]);
//         puts("");
//     }
//     return 0;
// }

// #include<cstdio>
// #include<cstring>
// #include<algorithm>
// #include<iostream>

// using namespace std;
// int arr[1010];
// int main(){
//     int n = 0;
//     cin >> n;
//     for(int i = 0;i < n;i++) cin >> arr[i];
//     sort(arr, arr + n - 1);
//     for(int i = n - 1;i >= 0;i--){
//         if(i != n - 1) printf(" ");
//         printf("%d", arr[i]);
//     }
//     return 0;
// }

// #include<cstdio>
// #include<algorithm>
// #include<cstdio>
// #include<set>

// using namespace std;

// const int N = 10010;
// int arr[N];

// int main(){
//     int n, x;
//     for(int i = 0;i < n;i++) cin >> arr[i];
//     arr[n] = x;
//     cin >> x;
//     sort(arr, arr + n + 1);
//     for(int i = 0;i < n;i++) {
//         if(i) printf(" ");
//         printf("%d", arr[i]);
//     }
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// char ch[10010];
// char x;
// int  main()
// {
//     scanf("%c%s", &x, ch);
//     int ans = -1;
//     for (int i = 0; ch[i] != 0; i++) {
//         if (x == ch[i])
//             ans = i;
//     }
//     if (ans == -1)
//         puts("Not Found");
//     else
//         printf("%d", ans);
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// char ch;
// char x;
// int  main()
// {
//     x = getchar();
//     getchar();
//     int ans = -1;
//     int i   = 0;
//     while ((ch = getchar()) != '\n') {
//         if (x == ch)
//             ans = i;
//         i++;
//     }
//     if (ans == -1)
//         puts("Not Found");
//     else
//         printf("index = %d\n", ans);
//     return 0;
// }

// #include<cstdio>
// #include<algorithm>
// #include<cstring>
// #include<iostream>

// using namespace std;

// const int N = 100010;
// int arr[N];
// int n, x;

// int main(){
//     cin >> n >> x;
//     int ans = -1;
//     for(int i = 0;i < n;i++){
//         cin >> arr[i];
//         if(arr[i] == x) ans = i;
//     }
//     if(ans == -1) puts("Not Found");
//     else printf("%d", ans);
//     return 0;
// }

// #include <cstdio>
// #include <iostream>

// using namespace std;

// const int N = 100010;
// int       arr[N];
// int       n, x;

// int main()
// {
//     cin >> n >> x;
//     bool flag = false;
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//         if (arr[i] == x) {
//             printf("%d\n", arr[i]);
//             flag = true;
//         }
//     }
//     if(!flag) puts("Not Found");
//     return 0;
// }
