#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100010;

struct chainNode{
	int value;
	chainNode* next;
	chainNode(int value, chainNode* next){
		this->value = value;
		this->next = next;
	}
};

class linked_list{
	private:
		chainNode* chain_head;
		int chain_size;
	public:
		linked_list(){
			chain_head = NULL;
			chain_size = 0;
		}
		int size(){
			return chain_size;
		}
		void add_to_head(int x){
			chain_head = new chainNode(x, chain_head);
			chain_size++;
		}
		void show(){
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
	linked_list* list = new linked_list();
	while(n--){
		int item;
		scanf("%d", &item);
		list->add_to_head(item);
	}
	list->show();
	delete(list);
	return 0;
}