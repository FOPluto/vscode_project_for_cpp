#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 50;

int arr[N][N], n, flag1[N], flag2[N];

vector<int> res, temp;
bool st[N];

void find(int a, int u){
    if(u == n && arr[a][1] == 1){
        if(res.size()){
            int idx = 0;
            while(res[idx] == temp[idx]) idx ++;
            if(res[idx] > temp[idx]) {
                res = temp;
            }
        } else {
            res = temp;
        }
        return;
    }
    
    bool is_win = false;
    
    for(int i = 1;i <= n;i++){
        if(!st[i] && arr[i][1] == 1){
            is_win = true;
            break;
        }
    }
    
    
    if(!is_win) return;
    else
        for(int i = 1;i <= n;i++){
            if(arr[a][i] == 1 && !st[i]){
                temp.push_back(i);
                st[i] = true;
                find(i, u + 1);
                temp.pop_back();
                st[i] = false;
            }
        }
    
}

int p[N], num_p;

int find_p(int x){
    if(x != p[x]) p[x] = find_p(p[x]);
    return p[x];
}

int main(){
    scanf("%d", &n);
    cin.get();
    for(int i = 1;i <= n;i++) p[i] = i;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            char ch;
            ch = getchar();
            if(ch == 'L'){
                arr[j][i] = 1;
                flag1[i] ++;
                flag2[j] ++;
                int aa = find_p(i), bb = find_p(j);
                p[bb] = aa;
            }
            else if(ch == 'W') {
                arr[i][j] = 1;
                int aa = find_p(i), bb = find_p(j);
                p[aa] = bb;
                flag1[j] ++;
                flag2[i] ++;
            }
            else if(ch == 'D') arr[i][j] = 0;
            else arr[i][j] = 0x3f3f3f3f;
        }
        cin.get();
    }
    
    for(int i = 1;i <= n;i ++){
        if(!flag1[i] || !flag2[i]){
            puts("No Solution");
            return 0;
        }
    }
    
    for(int i = 2;i <= n;i ++){
        if(p[i] != p[i - 1]){
            puts("No Solution");
            return 0;
        }
    }
    
    temp.push_back(1);
    st[1] = true;
    find(1, 1);
    
    //find();
    
    for(int i = 0;i < res.size();i++){
        if(i) printf(" ");
        printf("%d", res[i]);
    }
    
    return 0;
}