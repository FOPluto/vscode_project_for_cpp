// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// const int N = 100010;
// int       path[N];
// bool st[N];
// int       n;

// void dfs(int u) {
//     if(u == n){
//         for(int i = 0;i < n;i++) printf("%d ",path[i]);
//         puts("");
//         return;
//     }
//     for(int i = 1;i <= n;i++){
//         if(!st[i]){
//             path[u] = i;
//             st[i] = true;
//             dfs(u + 1);
//             st[i] = false;
//         }
//     }
// }

// int main()
// {
//     scanf("%d", &n);

//     dfs(0);

//     return 0;
// }

// #include <iostream>

// using namespace std;

// const int N = 100010;
// int       path[N];
// int       n;
// bool      st[N];

// void dfs(int u)
// {
//     if (u == n) {
//         for (int i = 0; i < u; i++)
//             printf("%d ", path[i]);
//         puts("");
//         return;
//     }
//     for (int i = 1; i <= n; i++) {
//         if (!st[i]) {
//             path[u] = i;
//             st[i]   = true;
//             dfs(u + 1);
//             st[i] = false;
//         }
//     }
// }

// int main()
// {
//     scanf("%d", &n);

//     dfs(0);

//     return 0;
// }

// #include <algorithm>
// #include <iostream>

// using namespace std;

// const int N = 100010;
// int       n;
// bool      st[N];
// int       path[N];

// void dfs(int u)
// {
//     if (u == n) {
//         for (int i = 0; i < n; i++)
//             printf("%d ", path[i]);
//         puts("");
//         return;
//     }

//     for (int i = 1; i <= n; i++) {
//         if (!st[i]) {
//             path[u] = i;
//             st[i]   = true;
//             dfs(u + 1);
//             st[i] = false;
//         }
//     }
// }

// int main()
// {
//     scanf("%d", &n);

//     dfs(0);

//     return 0;
// }

// #include <cstring>
// #include <iostream>

// using namespace std;
// class Girl;
// class Boy {
//   private:
//     char* name;
//     int   age;

//   public:
//     Boy(char* n, int a)
//     {
//         name = new char[strlen(n) + 1];
//         strcpy(name, n);
//         age = a;
//     }
//     ~Boy()
//     {
//         delete name;
//     }
//     void output()
//     {
//         cout << "姓名：" << name << "  年龄:" << age << endl;
//     }
// };
// class Girl {
//   private:
//     char* name;
//     int   age;

//   public:
//     Girl(char n[], int a)
//     {
//         name = new char[strlen(n) + 1];
//         strcpy(name, n);
//         age = a;
//     }
//     ~Girl()
//     {
//         delete name;
//     }
//     void output()
//     {
//         cout << "姓名：" << name << "  年龄:" << age << endl;
//     }
// };

// int main()
// {
//     Boy  a("张三", 19);
//     Girl b("李四", 20);
//     a.output();
//     b.output();
//     getchar();
// }

#include <iostream>
using namespace std;

int main()
{
    cout << ("1233" < "1234") << endl;
}