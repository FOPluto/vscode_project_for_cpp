// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int main()
// {
//     for (int i = 2; i <= 10000; i++) {
//         int                     t   = i;
//         int                     res = 0;
//         unordered_map<int, int> m;
//         for (int j = 1; j < i; j++) {
//             if (t % j == 0) {
//                 m[j]++;
//             }
//         }
//         for (auto t : m) {
//             int a = t.first, b = t.second;
//             if (b)
//                 res += a;
//         }
//         if (res == i)
//             printf("%d is the wanquanshu!\n", i);
//     }
//     return 0;
// }

// #include<cstdio>
// #include<cstring>
// #include<cstdio>
// #include<iostream>
// const int N = 100010;

// int main(){

//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// const int N = 100010;

// long long dp[N], n;

// long long feb(int x)
// {
//     if (x <= 2)
//         return 1;
//     if (dp[x])
//         return dp[x];  //使用dp算法记忆存储可以加速

//     dp[x] = feb(x - 1) + feb(x - 2);
//     return dp[x];
// }

// int main()
// {
//     cin >> n;
//     cout << feb(n) << endl;
//     return 0;
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// bool judge(int x)
// {
//     bool temp = true;

//     for (int i = 2; i <= x / i; i++) {
//         if (x % i == 0) {
//             temp = false;
//             break;
//         }
//     }
//     return temp;
// }

// pair<int, int> pp;

// int main()
// {
//     for (int i = 4; i <= 200; i += 2) {
//         int  num = i;
//         bool flag;
//         for (int j = 2; j < i; j++) {
//             flag = false;
//             for (int k = 2; k < i; k++) {
//                 if (judge(j) && judge(k)) {
//                     if (j + k == num) {
//                         flag     = true;
//                         pp.first = j, pp.second = k;
//                         break;
//                     }
//                 }
//             }
//             if (flag)
//                 break;
//         }
//         printf("%d=%d+%d\n", i, pp.first, pp.second);
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// void test(int m, float& n);
// int  main()
// {
//     int   test_m = 5;
//     float test_n = 5.0;
//     test(test_m, test_n);
//     cout << "************main***********" << endl;
//     cout << "test_m=" << test_m << endl;
//     cout << "test_n=" << test_n << endl;
//     return 0;
// }
// void test(int m, float& n)
// {
//     m = m + 5;
//     n = n + m + 10.5;
//     cout << "************test***********" << endl;
//     cout << "n=" << n << endl;
//     cout << "m=" << m << endl;
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <map>
// #include <unordered_map>

// using namespace std;

// string t[13] = {"Ox",   "Tiger",  "Rabbit",  "Dragon", "Snake", "Horse",
//                 "Goat", "Monkey", "Rooster", "Dog",    "Pig",   "Rat"};

// int n;

// unordered_map<string, int> mm;
// unordered_map<string, int> backup;

// int main()
// {
//     cin >> n;
//     mm["Bessie"] = 0;
//     while (n--) {
//         string a, b, c, d, e, f, g, h;
//         cin >> a >> b >> c >> d >> e >> f >> g >> h;
//         if (d == "previous") {
//             int temp;
//             for (int i = 0; i < 13; i++) {
//                 if (t[i] == e) {
//                     temp = i;
//                     break;
//                 }
//             }
//             if (temp == mm[h])
//                 mm[a] = mm[h] - 12;
//             else mm[a] = mm[h] - ((mm[h] - temp) % 12 + 12) % 12;
//         }
//         else {
//             int temp;
//             for (int i = 0; i < 13; i++) {
//                 if (t[i] == e) {
//                     temp = i;
//                     break;
//                 }
//             }
//             if (temp == mm[h])
//                 mm[a] = mm[h] + 12;
//             else
//                 mm[a] = mm[h] + ((temp - mm[h]) % 12 + 12) % 12;
//         }
//     }
//     cout << abs(mm["Bessie"] - mm["Elsie"]) << endl;
//     return 0;
// }
