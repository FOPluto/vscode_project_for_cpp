// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <stack>

// using namespace std;

// int n, L;

// const int N = 100010;

// struct Node{
//     int val;
//     Node* l;
//     Node* r;
// };

// Node* create(Node* tree, int num){
//     if(!tree){
//         tree = new Node();
//         tree->val = num;
//     } 
//     else if(num < tree->val) tree->l = create(tree->l, num);
//     else if(num > tree->val) tree->r = create(tree->r, num);
//     return tree;
// }

// bool judge(Node* node1, Node* node2){
//     if(!node1 && !node2) return true;
//     else if(node1 && !node2) return false;
//     else if(!node1 && node2) return false;
//     else if(node2->val != node1->val) return false;
//     else return (judge(node1->l, node2->l) && judge(node1->r, node2->r));
// }

// int main(){
//     while(1){
//         cin >> n;
//         if(!n) return 0;
//         cin >> L;
//         Node* head = NULL;
//         for(int i = 0;i < n;i++){
//             int a;
//             cin >> a;
//             head = create(head, a);
//         }
//         while(L --){
//             Node* demo = NULL;
//             for(int i = 0;i < n;i++){
//                 int a;
//                 cin >> a;
//                 demo = create(demo, a);
//             }
//             bool flag = judge(head, demo);
//             if(flag) puts("Yes");
//             else puts("No");
//         }
//     }
// }




// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <iostream>
// #include <stack>

// #define ERROR 0x3f3f3f3f

// using namespace std;

// int add(int num1, int num2){
// 	return num1 + num2;
// }

// int mul(int num1, int num2){
// 	return num1 - num2;
// }

// int muti(int num1, int num2){
// 	return num1 * num2;
// }

// int dev(int num1, int num2){
// 	return num1 / num2;
// }

// int do_compute(int num1, int num2, char cac){
// 	switch(cac){
// 		case '+':
// 			return add(num1, num2); 
// 		case '-':
// 			return mul(num1, num2);
// 		case '*':
// 			return muti(num1, num2);
// 		case '/':
// 			if(num2 != 0)
// 				return dev(num1, num2);
// 			else
// 				return ERROR;
// 	}
// }

// //struct chainNode{
// //	int value;
// //	chainNode* next;
// //	chainNode(int value, chainNode* next){
// //		this->value = value;
// //		this->next = next;
// //	}
// //};
// //
// //class stack{
// //	private:
// //	chainNode* stack_top;
// //	int size;
// //	
// //	public:
// //	stack(){
// //		//???????????? 
// //		stack_top = NULL;
// //		size = 0;
// //	}	
// //	
// //	void size(){
// //		//????????????????????????????????????????????? 
// //		return this->size;
// //	}
// //		
// //	void pop(){
// //		//??????????????????
// //		auto temp = stack_top->next;
// //		delete stack_top;
// //		stack_top = temp;
// // 	 }
// // 	void push(int x){
// // 		//??????????????????????????? 
// // 		stack_top = new chainNode(x, stack_top);
// // 		size++;
// //	 }
// //	int top(){
// //		//?????????????????? 
// //		return stack_top->value;
// //	 }
// //};

// class caculator{
// 	private:
//     stack<int> num; 
//     stack<char> cac;
//     public:
//     void input();
//     void compute();
// };

// void caculator::input(){
// 	int n;
// 	scanf("%d", &n);
// 	for(int i = 0;i < n;i++){
// 		int num = 0;
// 		scanf("%d", &num);
// 		this->num.push(num);
// 	}
// 	cin.get();
// 	for(int i = 0;i < n - 1;i++){
// 		char c;
// 		cin >> c;
// 		cac.push(c);
// 	} 
// }

// void caculator::compute(){
// 	int res = 0;
// 	while(num.size() >= 1 && !cac.empty()){
// 		int num1 = num.top();
// 		num.pop();
// 		int num2 = num.top();
// 		num.pop();
// 		char t = cac.top();
// 		cac.pop();
// 		res = do_compute(num2, num1, t);
// 		if(res == ERROR){
// 			printf("ERROR: %d/0\n", num2);
// 			return;
// 		}
// 		num.push(res);
// 	}
// 	printf("%d\n", res);
// }

// int main(){
//     caculator* c = new caculator();
//     c->input();
//     c->compute();
//     return 0;
// }


// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <cstring>

// using namespace std;

// const int N = 100010;  // N????????????????????????

// struct chainNode{   // ??????????????????????????????
// 	int value;    // ????????????
// 	chainNode* next;   // ????????????????????????
// 	chainNode(int value, chainNode* next){  // ?????????????????????
// 		this->value = value;
// 		this->next = next;
// 	}
// };

// class linked_list{
// 	private:
// 		chainNode* chain_head;  // ?????????
// 		int chain_size;   // ???????????????
// 	public:
// 		linked_list(){  // ???????????????????????????
// 			chain_head = NULL;
// 			chain_size = 0;
// 		}
// 		int size(){   // ????????????size
// 			return chain_size;
// 		}
// 		void add_to_head(int x){   // ??????????????????????????????
// 			chain_head = new chainNode(x, chain_head);
// 			chain_size++;
// 		}
// 		void show(){   // ??????????????????????????????????????????????????????
// 			int ans[N], idx = 0;
// 			for(chainNode* i = chain_head;i != NULL;i = i->next){
// 				ans[idx ++] = i->value;
// 			}
// 			for(int i = idx - 1;i >= 0;i--){
// 				if(i != idx - 1) printf(" ");
//                 printf("%d", ans[i]);
// 			}
// 		}
// };

// int n;

// int main(){
// 	scanf("%d", &n);
// 	linked_list* list = new linked_list();  //?????????
// 	while(n--){
// 		int item;
// 		scanf("%d", &item);
// 		list->add_to_head(item);  // ??????????????????
// 	}
// 	list->show();
// 	delete(list);  //?????????
// 	return 0;
// }



// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <iostream>
// #include <stack>

// #define ERROR 0x3f3f3f3f   // ??????????????????????????????????????????

// using namespace std;


// // ?????????????????????
// int add(int num1, int num2){
//     return num1 + num2;
// }

// int mul(int num1, int num2){
//     return num1 - num2;
// }

// int muti(int num1, int num2){
//     return num1 * num2;
// }

// int dev(int num1, int num2){
//     return num1 / num2;
// }

// // do_compute ???????????????cac??????????????????num1???num2???
// int do_compute(int num1, int num2, char cac){
//     switch(cac){
//         case '+':
//             return add(num1, num2); 
//         case '-':
//             return mul(num1, num2);
//         case '*':
//             return muti(num1, num2);
//         case '/':
//             if(num2 != 0)
//                 return dev(num1, num2);
//             else
//                 return ERROR;
//     }
// }

// // ????????????????????????????????????caculator???
// class caculator{
//     private:
//     stack<int> num; 
//     stack<char> cac;
//     public:
//     void input();
//     void compute();
// };

// // ????????????????????????
// void caculator::input(){
//     int n;
//     scanf("%d", &n);  // ???????????????
//     for(int i = 0;i < n;i++){  // ??????n????????????????????????stack??????
//         int num = 0;
//         scanf("%d", &num);
//         this->num.push(num);
//     }
//     cin.get(); // ??????cin.get()?????????????????????
//     for(int i = 0;i < n - 1;i++){
//         char c;
//         cin >> c;
//         cac.push(c);   // ????????????
//     } 
// }

// // ???????????????
// void caculator::compute(){
//     int res = 0;
//     while(num.size() >= 1 && !cac.empty()){
//         int num1 = num.top();
//         num.pop();
//         int num2 = num.top();
//         num.pop();
//         // ????????????????????????????????????????????????
//         char t = cac.top();
//         cac.pop();
//         // ????????????????????????????????????????????????
//         res = do_compute(num2, num1, t);
//         if(res == ERROR){ // ??????????????????
//             printf("ERROR: %d/0\n", num2);
//             return;
//         }
//         num.push(res);  // 
//     }
//     printf("%d\n", res);
// }

// int main(){
//     caculator* c = new caculator();   //??????acculator
//     c->input();// ?????????
//     c->compute();// ???????????????
//     return 0;
// }


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