#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>

#define ERROR 0x3f3f3f3f

using namespace std;

int add(int num1, int num2){
	return num1 + num2;
}

int mul(int num1, int num2){
	return num1 - num2;
}

int muti(int num1, int num2){
	return num1 * num2;
}

int dev(int num1, int num2){
	return num1 / num2;
}

int do_compute(int num1, int num2, char cac){
	switch(cac){
		case '+':
			return add(num1, num2); 
		case '-':
			return mul(num1, num2);
		case '*':
			return muti(num1, num2);
		case '/':
			if(num2 != 0)
				return dev(num1, num2);
			else
				return ERROR;
	}
}

//struct chainNode{
//	int value;
//	chainNode* next;
//	chainNode(int value, chainNode* next){
//		this->value = value;
//		this->next = next;
//	}
//};
//
//class stack{
//	private:
//	chainNode* stack_top;
//	int size;
//	
//	public:
//	stack(){
//		//构造函数 
//		stack_top = NULL;
//		size = 0;
//	}	
//	
//	void size(){
//		//返回栈的大小（其中元素的个数） 
//		return this->size;
//	}
//		
//	void pop(){
//		//删除栈顶元素
//		auto temp = stack_top->next;
//		delete stack_top;
//		stack_top = temp;
// 	 }
// 	void push(int x){
// 		//将新的元素推到栈中 
// 		stack_top = new chainNode(x, stack_top);
// 		size++;
//	 }
//	int top(){
//		//返回栈顶元素 
//		return stack_top->value;
//	 }
//};

class caculator{
	private:
    stack<int> num; 
    stack<char> cac;
    public:
    void input();
    void compute();
};

void caculator::input(){
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		int num = 0;
		scanf("%d", &num);
		this->num.push(num);
	}
	cin.get();
	for(int i = 0;i < n - 1;i++){
		char c;
		cin >> c;
		cac.push(c);
	} 
}

void caculator::compute(){
	int res = 0;
	while(num.size() >= 1 && !cac.empty()){
		int num1 = num.top();
		num.pop();
		int num2 = num.top();
		num.pop();
		char t = cac.top();
		cac.pop();
		res = do_compute(num2, num1, t);
		if(res == ERROR){
			printf("ERROR: %d/0\n", num2);
			return;
		}
		num.push(res);
	}
	printf("%d\n", res);
}

int main(){
    caculator* c = new caculator();
    c->input();
    c->compute();
    return 0;
}