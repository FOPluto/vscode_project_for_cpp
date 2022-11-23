// #include<cstdio>
// #include<cstring>
// #include<iostream>

// using namespace std;

// int score[100] = {5, 5, 10, 10, 15, 15, 20, 20, 25, 25, 25, 25, 30, 30, 30};
// int main(){
//     for(int i = 0;i < 3;i++){
//         int sum1 = 0;
//         int sum2 = 0;
//         int sum3 = 0;
//         for(int j = 0;j < 10;j++){
//             for(int k = 0;k < 15;k++){
//                 int a = 0;
//                 cin >> a;
//                 if(k < 8) sum1 += a;
//                 else if(k < 12) sum2 += a;
//                 else sum3 += a;
//             }
//             if(sum1 < 800) printf("%d ", sum1);
//             else if(sum2 < 400) printf("%d ", sum2 + sum1);
//             else printf("%d ", sum1 + sum2 + sum3);
//         }
//     }
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

string str[14] = {"DaDan",
                  "HuJia",
                  "GuaA",
                  "I'm speechless Maybe double kill",
                  "100% winning rate, playing wild without rules",
                  "Dragonfly skimming the water",
                  "Don't break my 1-game winning streak",
                  "I even want to fight back",
                  "It's not without experts",
                  "HuLuGay",
                  "I really can't stand it",
                  "JiXianLa",
                  "Crab step",
                  "Real c"};

int main()
{
    int n = 0;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;
        string ans;
        int    num = 0;
        for (int i = 0; i < input.length(); i++) {
            for (int k = 0; k < 14; k++) {
                int  n    = 0;
                bool flag = true;
                int  j;
                while (i + j < input.length()) {
                    bool temp = true;
                    for (j = 0; j < str[i].length(); j++) {
                        if (str[i][j] != input[i + j]) {
                            temp = false;
                            break;
                        }
                        i += j;
                    }
                    if (temp)
                        num++;
                }
            }
        }
        if (num)
            for (int i = 0; i < num; i++)
                printf("Wang");
        else
            printf("What are you barking at");
        puts("");
    }
    return 0;
}

// #include <iostream>

// using namespace std;

// int       m;
// const int N = 100010;
// int       arr[N];
// int       num[N];

// int main()
// {
//     cin >> m;
//     for (int i = 0; i < m; i++) {
//         int k = 0;
//         cin >> k;
//         num[k++];
//         arr[i] = k;
//     }
//     pair<int, int> max;
//     for (int i = 0; i < m; i++) {
//         if (max.second < num[arr[i]]) {
//             max.first  = arr[i];
//             max.second = num[arr[i]];
//         }
//     }
//     cout << max.first << " " << max.second << endl;

//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// const int n = 100010;
// string    arr[n][4];
// int       num[n];
// int       ans[n];
// int       n;

// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         string input1, input2, str1, str2;
//         cin >> input1 >> input2 >> num[i];
//         for (int j = input1.length() - 1; j >= 0; j--)
//             str1 += input1[j];
//         for (int j = input2.length() - 1; j >= 0; j--)
//             str2 += input2[j];
//         arr[i][0] = str1, arr[i][1] = str2;
//     }
//     string str1, str2;
//     cin >> str1 >> str2;
//     cout << str1 << endl;
//     for (int i = 0; i < 3; i++) {
//         int ma = 0;
//         if (str1[9] != '9')
//             str1[9]++;
//         else {
//             str1[8]++;
//             str1[9] = '0';
//         }
//         string str01, str02;
//         for (int j = str01.length() - 1; j >= 0; j--)
//             str01 += str1[j];
//         for (int j = str02.length() - 1; j >= 0; j--)
//             str02 += str1[j];
//         for (int j = 1; j <= n; j++) {
//             if (arr[j][0] < str01)
//                 continue;
//             else if (arr[j][0] == str01 && arr[j][1] < str02)
//                 continue;
//             if (num[j] > num[ma])
//                 ma = j;
//         }
//         printf("%d ", ma);
//     }
//     return 0;
// }

// #include <algorithm>
// #include <cstring>
// #include <iostream>
// #include <queue>
// using namespace std;

// const int N = 100010;

// int  n, m, s, q;
// char veg[N], outside[N], hove[N];
// int  tv, to, th;
// int  hv = -1, ho = -1, hh = -1;

// int main()
// {
//     cin >> n >> m >> s >> q;
//     for (int i = 0; i < m; i++) {
//         char ch;
//         cin >> ch;
//         veg[++hv] = ch;
//     }
//     while (q--) {
//         char ch[2];
//         scanf("%s", ch);
//         if (ch[0] == 'S') {
//             hove[++hh] = veg[tv++];
//         }
//         else {
//             outside[++ho] = veg[--hv];
//         }
//     }
//     for (int i = to; i <= ho; i++) {
//         cout << outside[i];
//     }
//     return 0;
// }
