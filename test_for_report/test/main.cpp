#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

string str;

int cnt, point, space = 2;  // 分别用于计所用到的点，所要填上的空格
//初始值为2
int mark, use, temp, tp;
void find(){  //去除每一行中前面的空格
    while(str[point] == ' ') point ++;
}

int function_find(){  //用于处理else if while for这些关键字的格式
    if(str.substr(point, 2) == "if" && str[point + 2] == '(' || str[point + 2] == ' ') return 2;
    else if(str.substr(point, 3) == "for" && str[point + 3] == '(' || str[point + 3] == ' ') return 3;
    else if(str.substr(point, 4) == "else" && str[point + 4] == '(' || str[point + 4] == ' ') return 4;
    else if(str.substr(point, 5) == "while" && str[point + 5] == '(' || str[point + 5] == ' ') return 5;
    return 0;
}

int main(){
    getline(cin, str);
    find();
	for (int i = point; str[i] != ')'; i++) cout << str[i];
	cout << ")\n{\n";
    point = str.find('{') + 1;
    while(1) {
        find();
        int temp = function_find();
        if(str[point] == '{') {
            for(int i = 0;i < space;i++) cout << " ";
            puts("{");
            space += 2;//每一层是两个空格
            //每一个前括号都要往右边进一位
			point ++;
        } else if (str[point] == '}'){
            space -= 2;
            //每一个后括号是往左边靠一下
            find();
            if (function_find() == 4) return 0;
            while (mark) {
                space -= 2;
                for(int i = 0;i < space;i++) cout << " ";
                cout << "}\n";
                mark--;
            } 
            if(space == 0) return 0;
            point ++;
        } else if (temp) {
			for(int i = 0;i < space;i++) cout << " ";
			cout << str.substr(point, temp);
			point += temp;
			if (temp != 4) {
				find();
				tp = point;
				cnt = 0;
				while(tp < str.size()) {
					if (str[tp] == '(') cnt++;
					else if (str[tp] == ')') cnt--;
					tp++;
					if (cnt == 0) break;
				}
				cout << ' ' << str.substr(point, tp - point);
				point = tp;
			}
			cout <<  " {\n";
			space += 2;
			find();
			if (str[point] != '{') {
				use = 1;
				mark++;
			} else {
				use = 0;
				point++;
			}
		} else {
			for(int i = 0;i < space;i++) cout << " ";
			cnt = str.find(';', point);
			cout << str.substr(point, cnt - point + 1) << '\n';
			point = cnt + 1;
			if (use && mark) {
				space -= 2;
			    for(int i = 0;i < space;i++) cout << " ";
				cout << "}\n";
				mark--;
                find();
                if (function_find() == 4) return 0;
                while (mark) {
                    space -= 2;
                    for(int i = 0;i < space;i++) cout << ' ';
                    cout << "}\n";
                    mark--;
                } 
			}
		}
    }
    return 0;
}