#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
const int N = 100010;

typedef pair<int, string> PII;

unordered_map<string, int> mm;
PII ans[N];
int idx;

int main(){
    scanf("%d", &n);
    while(n --){
        string str;
        getline(cin, str);
        bool start = false;
        for(int i = 0;i < str.length();i++){
            // 不是话题的直接略过
            if(str[i] == '#' && !start){
                start = true;
                string temp = "";
                // 表示已经开始读取话题
                while(i < str.length() && str[++ i] != '#'){
                    char ch = str[i];
                    if(ch >= 'A' && ch <= 'Z') ch += 32;
                    // 除了数字和字母,只剩下了符号就直接continue
                    bool flag = false;
                    if(ch >= '0' && ch <= '9')
                        flag = true;
                    else if(ch >= 'a' && ch <= 'z')
                        flag = true;
                    
                    if(!flag) continue;
                    // 将元素添加到答案中
                    temp.append(1, ch);
                }
                start = false;
                mm[temp] ++;
            }
        }
    }
    for(auto item : mm){
        ans[idx ++] = {item.second, item.first};
    }
    sort(ans, ans + idx, [](PII a1, PII a2){
        return a1.first > a2.first;
    });
    cout << ans[0].second << endl << ans[0].first << endl;
        printf("And %d more ...\n", idx - 1);
    return 0;
}