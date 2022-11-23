#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

char ss[10010];

int num_ans;

void floor_puts(){
    stack<int> q;
    q.push(1);
    while(!q.empty()) {
        int idx = q.top();
        cout << ss[idx];
        q.pop();
        if(ss[2 * idx] != '#' && ss[2 * idx] != '\0'){
            q.push(2 * idx);
        }
        if(ss[2 * idx + 1] != '#' && ss[2 * idx + 1] != '\0'){
            q.push(2 * idx + 1);
        }
    }
    puts("");
}

void front_puts(){
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int idx = q.front();
        cout << ss[idx];
        q.pop();
        if(ss[2 * idx] != '#' && ss[2 * idx] != '\0'){
            q.push(2 * idx);
        }
        if(ss[2 * idx + 1] != '#' && ss[2 * idx + 1] != '\0'){
            q.push(2 * idx + 1);
        }
    }
    puts("");
}

void back_puts(){
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int idx = q.front();
        cout << ss[idx];
        q.pop();
        if(ss[2 * idx + 1] != '#' && ss[2 * idx + 1] != '\0'){
            q.push(2 * idx + 1);
        }
        if(ss[2 * idx] != '#' && ss[2 * idx] != '\0'){
            q.push(2 * idx);
        }
    }
    puts("");
}

int main(){
    scanf("%s", ss + 1);
    cin.get();
    if(ss[1] == '#') puts("0");
    else {
        floor_puts();
        front_puts();
        back_puts();
    }
    return 0;
}

