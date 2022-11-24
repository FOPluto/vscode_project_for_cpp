#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

const int N = 100010;

int n;

struct treeNode{
int v;
int l, r;
};

bool st[N];

vector<treeNode> t;

int main(){
scanf("%d", &n);

for(int i = 0;i < n;i++) {
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

const int N = 100010;

int n;

struct treeNode{
    int v;
    int l, r;
};

bool st[N];

vector<treeNode> t;

int main(){
    scanf("%d", &n);
    
    for(int i = 0;i < n;i++) {
        treeNode item;
        cin >> item.v;
        t.push_back(item);
    }
    
    for(int i = 0;i < n;i++){
        t[i].r = t[i].l = -1;
    }
    int sum = 0;
    while(t.size() > 1){
        //每一次取出来元素之前进行一次排序，确保弹出来的是最小的
        sort(t.begin(), t.end(), [](const treeNode &t1, const treeNode &t2){
            return t1.v > t2.v;
        });
        auto a = t.back();
        t.pop_back();
        auto b = t.back();
        t.pop_back();
        treeNode c;
        c.v = a.v + b.v;
        t.push_back(c);
        sum += a.v + b.v;
    }
    cout << sum << endl;
    return 0;
}
