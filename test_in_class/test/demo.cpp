#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>


using namespace std;

const int N = 1010;

unordered_map<int, int> m;

int arr[N], n, p;

typedef pair<int, int> PII;

PII find(int x){
    if(x >= x + 1) return {arr[x - 2], arr[x - 1]};
    else if(x <= 0) return {arr[x + 1], arr[x + 2]};
    else return {arr[x - 1], arr[x + 1]};
}

int main(){
    scanf("%d", &n);
    while(n--){

        memset(arr, sizeof arr, 0x3f);
        scanf("%d", &p);

        int idx = 0;

        for(int i = 0;i < p;i++){
            int num;
            scanf("%d", &num);
            if(!m.count(num)){
                arr[idx ++] = num; 
                m[num] = 1;
            }
            else m[num] ++;
        }
        int max = 0, num = -1;

        p = idx;

        sort(arr, arr + p);

        int res = 0x3f3f3f3f;

        for(int i = 0;i < p;i++){
            if(m[arr[i]] == 1){
                auto ii = find(i);
                int ans = abs(arr[i] - ii.first) + abs(arr[i] - ii.second);
                res = min(res, ans);
            } else if(m[arr[i]] == 2){
                auto ii = find(i);
                int ans = min(abs(arr[i] - ii.first), abs(arr[i] - ii.second));
                res = min(res, ans);
            } else if(m[arr[i]] == 3){
                res = 0;
            }
        }
        cout << res << endl;
        m.clear();
    }
    return 0;
}
