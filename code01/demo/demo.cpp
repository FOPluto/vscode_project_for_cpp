#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

string M[4][2]={
    "can you","* can",
    "could you","* could",
    "I","you",
    "me","you"
};

int n;

int main(){
    scanf("%d", &n);
    cin.get();
    while(n--)
    {
        string s;
        getline(cin,s);
        cout<<s<<"\nAI: ";
        //去除首尾空格
        while (s[0]==' ')s.erase(s.begin());
		while (s[s.length()-1]==' ')s.erase(s.end()-1);
        //处理其他空格
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                //去除连续空格
                while (s[i + 1] == ' ')s.erase(i + 1, 1);
                //去除标点符号前空格
                if (isalnum(s[i+1])==0)
                {
                    s.erase(i, 1);
                }
            }
        }
        for(auto&c :s)
        {
            if (isupper(c)&&c!='I')c+=32;
            if (c=='?') c='!';
        }
        for(int j=0;j<4;j++)
        {
            int i = s.find(M[j][0]),l=M[j][0].length();
            while(i!=-1)
            {
                if ((i == 0 || !isalnum(s[i - 1])) && (i+l==s.size()||!isalnum(s[i + l])))
                    s.replace(i, l, M[j][1]);
                i = s.find(M[j][0],i+1);
            }
        }
        for(auto&c :s)
        {
            if (c=='*') c='I';
        }
        cout<<s<<"\n";
    }
    return 0;
}