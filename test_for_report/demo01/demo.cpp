#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100010;  // N可以用于创建数组

struct chainNode{   // 定义了一个链表的节点
    int value;    // 节点的值
    chainNode* next;   // 下一个节点的位置
    chainNode(int value, chainNode* next){  // 节点的构造函数
        this->value = value;
        this->next = next;
    }
};

class linked_list{
    private:
        chainNode* chain_head;  // 头结点
        int chain_size;   // 链表的大小
    public:
        linked_list(){  // 节点链表的构造函数
            chain_head = NULL;
            chain_size = 0;
        }
        int size(){   // 获得他的size
            return chain_size;
        }
        void add_to_head(int x){   // 将元素添加到头的位置
            chain_head = new chainNode(x, chain_head);
            chain_size++;
        }
        void show(){   // 展示，也就是依次将元素的内容打印出来，就是遍历
            int ans[N], idx = 0;
            for(chainNode* i = chain_head;i != NULL;i = i->next){
                ans[idx ++] = i->value;
            }
            for(int i = idx - 1;i >= 0;i--){
                if(i != idx - 1) printf(" ");
                printf("%d", ans[i]);
            }
        }
};

int n;

int main(){
    scanf("%d", &n);
    linked_list* list = new linked_list();  //先创建
    while(n--){
        int item;
        scanf("%d", &item);
        list->add_to_head(item);  // 添加到链表中
    }
    list->show();
    delete(list);  //后删除
    return 0;
}
