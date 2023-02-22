#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 100010;

int n, m;

struct code{
    vector<int> num;
    
    bool operator==(const code& c1){
        if(c1.num.size() == num.size()){
            for(int i = 0;i < c1.num.size();i++) if(c1.num[i] != num[i]) return false;
            return true;
        }
        return false;
    }
} node[N];

typedef pair<int, int> PII;

PII arr[N];
int idx;

int main(){
    scanf("%d%d", &n, &m);
    
    for(int i = 0;i < n;i++){
        code temp;
        for(int j = 0;j < m;j++){
            int num; scanf("%d", &num);
            temp.num.push_back(num);
        }
        bool t = false;
        for(int j = 0;j < idx;j++){
            if(temp == node[j]) {
                arr[j].first ++;
                t = true;
            }
        }
        if(!t){
            node[idx] = temp;
            arr[idx ++].first ++;
        }
    }
    for(int i = 0;i < idx;i++) arr[i].second = i;
    
    sort(arr, arr + idx, [](PII a1, PII a2){
        if(a1.first != a2.first) return a1.first > a2.first;
        int idx_temp = 0;
        while(node[a1.second].num[idx_temp] == node[a2.second].num[idx_temp]) idx_temp ++;
        return node[a1.second].num[idx_temp] < node[a2.second].num[idx_temp];
    });
    
    printf("%d\n", idx);
    
    for(int i = 0;i < idx;i++){
        if(i) puts("");
        printf("%d ", arr[i].first);
        for(int j = 0;j < node[arr[i].second].num.size();j++){
            if(j) printf(" ");
            printf("%d", node[arr[i].second].num[j]);
        }
    }
    return 0;
}