#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
//这里做一个简单的链表
const int N = 100010;

int  ne[N], e[N];
int  idx;
int  head = -1;
void add()
{
    int x;
    int t;
    printf("please input number:\n");
    scanf("%d", &x);
    e[idx]  = x;
    ne[idx] = head;
    head    = idx++;
    printf("add done\n");
    printf("---------------------\n");
}
void erase()
{
    int t = 0;
    printf("please input number:\n");
    scanf("%d", &t);

    for (int i = head; i != -1; i = ne[i]) {
        if (e[ne[i]] == t) {
            ne[i] = ne[ne[i]];
        }
    }

    printf("delete done\n");
    printf("---------------------\n");
}
void sort()
{
    printf("sort..\n");
}

int main()
{
    char IN;
    bool flag = false;
    while (1) {
        cin >> IN;
        switch (IN) {
            case 'A': add(); break;
            case 'D': erase(); break;
            case 'S': sort(); break;
            case 'Q': flag = true; break;
        }
        if (flag)
            break;
    }

    return 0;
}