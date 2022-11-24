#include <bits/stdc++.h>
using namespace std;
//point表示当前的位置
//space表示当前层前面的空格数，也就是我们所说的缩进
//mark表示层数
int point, space = 2, mark;
int cnt;
bool use;
string s;
int func(int c) {
    if (c == 0) while (s[point] == ' ') point++; // 除去前面的空格
    else if (c == 1) for (int i = 0; i < space; i++) cout << ' '; // 按照缩进格式输出空格
    else if (c == 2) { // 判断if else for while这些关键词
        if (s.substr(point, 2) == "if" && (s[point + 2] == '(' || s[point + 2] == ' ')) return 2;
        else if (s.substr(point, 3) == "for" && (s[point + 3] == '(' || s[point + 3] == ' ')) return 3;
        else if (s.substr(point, 4) == "else" && (s[point + 4] == '(' || s[point + 4] == ' ')) return 4;
        else if (s.substr(point, 5) == "while" && (s[point + 5] == '(' || s[point + 5] == ' ')) return 5;
    } else if (c == 3) { // 这一部分用于排除出代码体的时候所有的'}'
        func(0);
        if (func(2) == 4) return 0;
        while (mark) {
            space -= 2;
            func(1);
            cout << "}\n";
            mark--;
        } 
    }
    return 0;
}
int main() {
    getline(cin, s);
    func(0);
    for (int i = point; s[i] != ')'; i++) cout << s[i];
    cout << ")\n{\n";
    point = s.find('{') + 1;
    while (1) {
        func(0);
        int temp = func(2);
        if (s[point] == '{') {
            func(1);
            cout << "{\n";
            space += 2;
            point++;
        } else if (s[point] == '}') {
            space -= 2;
            func(1);
            cout << "}\n";
            if (space == 0) return 0;
            func(3);
            point++;
        } else if (temp) {
            func(1);
            cout << s.substr(point, temp);
            point += temp;
            if (temp != 4) {
                func(0);
                int tp = point;
                cnt = 0;
                while(tp < s.size()) {
                    if (s[tp] == '(') cnt++;
                    else if (s[tp] == ')') cnt--;
                    tp++;
                    if (cnt == 0) break;
                }
                cout << ' ' << s.substr(point, tp - point);
                point = tp;
            }
            cout <<  " {\n";
            space += 2;
            func(0);
            if (s[point] != '{') {
                use = true;
                mark++;
            } else {
                use = false;
                point++;
            }
        } else {
            func(1);
            cnt = s.find(';', point);
            cout << s.substr(point, cnt - point + 1) << '\n';
            point = cnt + 1;
            if (use && mark) {
                space -= 2;
                func(1);
                cout << "}\n";
                mark--;
                func(3);
            }
        }
    }
    return 0;
}
