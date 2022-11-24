#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

queue<int> A, B;

vector<int> ans;

int  n;

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++) { // 先输入
        int num;
        cin >> num;
        if(num % 2) A.push(num);
        else B.push(num);
    }
    
    while(!A.empty() || !B.empty()){ //循环跳出条件是所有的人都处理完
        if(!A.empty()) {// A弹出两个
            ans.push_back(A.front());
            A.pop();
            if(!A.empty()){
                ans.push_back(A.front());
                A.pop();
            }
        }
        if(!B.empty()) {// B弹出一个
            ans.push_back(B.front());
            B.pop();
        }
    }
    for(int i = 0;i < ans.size();i++){
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
