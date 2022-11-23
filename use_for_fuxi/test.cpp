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
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        if(num % 2) A.push(num);
        else B.push(num);
    }
    
    while(!A.empty() || !B.empty()){
        if(!A.empty()) {
            ans.push_back(A.front());
            A.pop();
            if(!A.empty()){
                ans.push_back(A.front());
                A.pop();
            }
        }
        if(!B.empty()) {
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