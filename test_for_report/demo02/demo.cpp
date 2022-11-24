#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>

#define ERROR 0x3f3f3f3f   // 代表错误的数字，这个数字很大

using namespace std;

// 四个计算的函数
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

// do_compute 是用来根据cac的类型来处理num1和num2的
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

// 将整个计算器的算法封装到caculator里
class caculator{
    private:
    stack<int> num; 
    stack<char> cac;
    public:
    void input();
    void compute();
};

// 这里是输入的函数
void caculator::input(){
    int n;
    scanf("%d", &n);  // 输入的数量
    for(int i = 0;i < n;i++){  // 输入n次数字，将其推到stack里边
        int num = 0;
        scanf("%d", &num);
        this->num.push(num);
    }
    cin.get(); // 这个cin.get()是为了吃掉回车
    for(int i = 0;i < n - 1;i++){
        char c;
        cin >> c;
        cac.push(c);   // 输入符号
    } 
}

// 计算的函数
void caculator::compute(){
    int res = 0;
    while(num.size() >= 1 && !cac.empty()){
        int num1 = num.top();
        num.pop();
        int num2 = num.top();
        num.pop();
        // 获取两个需要计算的数字，并且弹出
        char t = cac.top();
        cac.pop();
        // 获取一个需要计算的符号，并且弹出
        res = do_compute(num2, num1, t);
        if(res == ERROR){ // 假如返回错误
            printf("ERROR: %d/0\n", num2);
            return;
        }
        num.push(res);  // 
    }
    printf("%d\n", res);
}

int main(){
    caculator* c = new caculator();   //创建acculator
    c->input();// 先输入
    c->compute();// 后计算处理
    return 0;
}
