#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 21

using namespace std;

const int N = 30;

int row, col;

vector<string> error_info;

vector<string> print_info;

char ch;

//关键字表
const char *keyword[MAX] = {  "iostream", "void", "int",
                        "char", "string", "bool",
                        "return", "using", "namespace",
                        "main", "break", "include",
                        "begin", "end", "if", "else",
                        "while", "switch", "for", "else if", "std" };

//分解符表
const char* s1[11] = { ",", ";", "(", ")", "[", "]", "()", "[]", "{}", "{", "}"};

//算术运算符表
const char* s2[6] = { "+","-","*","/","++","--"};

//关系运算符表
const char* s3[7] = { "<=",">",">=","=",">",">=","<>" };


// 判断是否是数字
bool is_number(char ch) {
    return ch >= '0' && ch <= '9';
}

// 判断是否是字母
bool is_alpha(char ch) {
    return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}

bool is_symbol(char ch) {
    if (ch == ',' || ch == '.' || ch == ';' || 
        ch == '(' || ch == ')' || ch == '[' || 
        ch == ']' || ch == '{' || ch == '}' ||
        ch == '|' || ch == '+' || ch == '-' ||
        ch == '*' || ch == '<' || ch == '>' || 
        ch == '/' || ch == '=') {
        return true;
    }
    return false;
}

// 是否为分隔符
bool is_delimiter(char* takes) {
    for (int i = 0; i < 11; i++)
	{
		if (strcmp(takes, s1[i]) == 0) {
            return true;
        }
	}
	return false;
}

// 是否为运算符
bool is_operator(char* takes) {
    for (int i = 0; i < 6; i++)
	{
		if (strcmp(takes, s2[i]) == 0) {
            return true;
        }
	}
    for (int i = 0; i < 7; i++)
	{
		if (strcmp(takes, s3[i]) == 0) {
            return true;
        }
	}
	return false;
}


// 判断是否是关键字
bool is_key(char* takes) {
	for (int i = 0; i < MAX; i++)
	{
		if (strcmp(takes, keyword[i]) == 0) {
            return true;
        }
	}
	return false;
}


// 分析函数
void analyze(FILE* fpin) {
    while ((ch = fgetc(fpin)) != EOF) {
        // 空格 回车
		if (ch == ' ' || ch == '\t' || ch == '\n') {
            if(ch == '\n') row ++;
        }
        // 字母
        else if(is_alpha(ch)) {
            char takes[30] = { '\0' };
			int i = 0;
             // 后面是字母或者数字
            while (is_alpha(ch) || is_number(ch)) {
				takes[i] = ch;
				i++;
				ch = fgetc(fpin);
			}
			// 回退一个指针
			fseek(fpin, -1L, SEEK_CUR);
            // 判断是否为关键字或者标识符
            if(is_key(takes)) { // 关键字
                print_info.push_back("[Keyword] : " + string(takes));
            } else { // 标识符
                print_info.push_back("[Identifiers] : " + string(takes));
            }
        } 
        // 首字母是数字或者是点 
        else if(is_number(ch) || (ch == '.')) {
			bool mark = true;
			int i = 0;
			char takes[20] = { '\0' };
			while (is_number(ch) || is_alpha(ch) || (ch == '.' && is_number(fgetc(fpin))))
			{
				if (is_alpha(ch))
				{
					mark = false;
					if (ch == '.')fseek(fpin, -1L, SEEK_CUR);
					takes[i] = ch;
					i++;
					ch = fgetc(fpin);
				}
				else {
					if (ch == '.')fseek(fpin, -1L, SEEK_CUR);
					takes[i] = ch;
					i++;
					ch = fgetc(fpin);
				}
			}
			fseek(fpin, -1L, SEEK_CUR);
            //属于无符号常数
			if (mark) {
				print_info.push_back("[Constants] : " + string(takes));
			} else {
                // 如果判断为错误信息，则将信息输出到vector中
                error_info.push_back("[Error] : 未识别的标识符[" + string(takes) + "]");
            }
        }
        else if(is_symbol(ch)) {
            char takes[20] = { '\0' };
            bool mark = true;
			int i = 0;
            while (is_symbol(ch)) {
				takes[i] = ch;
				i++;
				ch = fgetc(fpin);
			}
            // 判断返回的字符串类型
            if(is_delimiter(takes)) {
                print_info.push_back("[Delimiter] : " + string(takes));
            } else if(is_operator(takes)) {
                print_info.push_back("[Operator] : " + string(takes));
            } else {
                error_info.push_back("[Error] : 未识别的符号[" + string(takes) + "]");
            }
        }
    }
}

// 展示结果函数
void show_info() {
    if(error_info.size()) {
        printf("Error\n");
        for(auto item : error_info) {
            cout << item;
            puts("");
        }
    } else {
        for(auto item : print_info) {
            cout << item;
            puts("");
        }
    }
}

// PL-0
int main(){
    char input[30];
	FILE* fpin;
	cout << "请输入需要检查的源文件名：\n" << endl;
	while(1) {
		cin >> input;
		if ((fpin = fopen(input, "r")) != NULL)
			break;
		else
			cout << "文件不存在" << endl;
	}
	cout << "词法分析结果:      " << endl;
	analyze(fpin);
    show_info();
	fclose(fpin);

    return 0;
}