#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

const int N = 50010;

int m;

struct Node{
    vector<int> son;
    vector<int> p;
    double res;
    int type;
	bool st;
    int res2;
} node[N];

int idx, flag[N], is_yezi[N];

double res[N];

double one_caculate(int t, double x){
    if(t == 4){
        return exp(x);
    } else if(t == 5){
        return log(x);
    } else {
        return sin(x);
    }
}

double two_caculate(int t, double x, double y){
    if(t == 1){
        return x + y;
    } else if(t == 2){
        return x - y;
    } else {
        return x * y;
    }
}

int main(){
    scanf("%d", &m);
    int n = m;
    while(m --){
        int t;
        cin >> t;
        if(t == 0){
            double num;
            cin >> num;
            node[idx].res = num;
            res[idx] = num;
            node[idx ++].type = t;
        } else if(t >= 4 && t <= 6){
            int i;
            cin >> i;
            flag[idx] ++;
            node[i].son.push_back(idx);
            node[idx].p.push_back(i);
            node[idx ++].type = t;
        } else if(t >= 1 && t <= 3){
            int i, j;
            cin >> i >> j;
            flag[idx] += 2;
            node[i].son.push_back(idx);
            node[j].son.push_back(idx);
            node[idx].p.push_back(i);
            node[idx].p.push_back(j);
            node[idx ++].type = t;
        }
    }
    
    queue<Node> q, qq;
    
    for(int i = 0;i < idx;i++){
        if(flag[i] == 0){
            q.push(node[i]);
            is_yezi[i] = true;
        }
    }
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for(int i = 0;i < t.son.size();i++){
            Node* j = &node[t.son[i]];
            if(j->type >= 4 && j->type <= 6) j->res = one_caculate(j->type, t.res);
            else j->res = two_caculate(j->type, node[j->p[0]].res, node[j->p[1]].res);
			if(!j->st) flag[t.son[i]] --;
			j->st = true;
            if(!flag[t.son[i]]) q.push(*j);
        }
    }
    // 求出来前向传播的结果
    printf("%.3lf ", node[n - 1].res);
    
    // 下面求解反向传播的过程
    qq.push(node[n - 1]);

    while(!qq.empty()){
        auto t = qq.front();
        qq.pop();
        if(t.type == 1){
            node[t.p[0]].res2 += 1;
            node[t.p[1]].res2 += 1;
        } else if(t.type == 2){
            node[t.p[0]].res2 += 1;
            node[t.p[1]].res2 -= 1;
        } else if(t.type == 3){
            node[t.p[0]].res2 += node[t.p[1]].res;
            node[t.p[1]].res2 += node[t.p[0]].res;
        } else if(t.type == 4){
            node[t.p[0]].res2 += exp(node[t.p[0]].res);
        } else if(t.type == 5){
            node[t.p[0]].res2 += 1 / node[t.p[0]].res;
        } else if(t.type == 6){
            node[t.p[0]].res2 += cos(node[t.p[0]].res);
        }
        for(int i = 0;i < t.p.size();i ++){
            int j = t.p[i];
            qq.push(node[j]);
        }
    }

    for(int i = 0;i < n;i++){
        if(is_yezi[i]){
            printf("%.3lf ", node[i].res2);
        }
    }


    return 0;
}