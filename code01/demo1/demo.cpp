#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

string words;
int level;

void ignore_space(int& t){
    while(words[t] == ' ') t ++;
}

void print_space(int space){
    while(space --) printf(" ");
}

int judge_func(string str, int& t){
    if(str.find("for", t) == t && (str[t + 3] == ' ' || str[t + 3] == '('))
        return 3;
    else if(str.find("if", t) == t && (str[t + 2] == ' ' || str[t + 2] == '('))
        return 2;
    else if(str.find("while", t) == t && (str[t + 5] == ' ' || str[t + 5] == '('))
        return 5;
    else if(str.find("else", t) == t && (str[t + 4] == ' ' || str[t + 4] == '('))
        return 4;
    else if(str.find("{", t) == t)
        return 1;
    else return 0;
}

int main(){
    int idx = 0;
    getline(cin, words);

    ignore_space(idx);

    int t = words.find(')');
    while(idx < t) cout << words[idx ++];
    cout << "\n{\n";
    level += 2;
    ignore_space(idx);

    idx ++;

    int tmp = 0;

    while(idx < words.length()){
        ignore_space(idx);
        if((tmp = judge_func(words, idx))){
            print_space(level);
            if(tmp == 1){
                printf("{\n");
                idx ++;
                level += 2;
                continue;
            } else if(tmp == 4){
                for(int j = 0;j < 4;j++) printf("%c", words[idx + j]);
            }
        }
    }
    
}