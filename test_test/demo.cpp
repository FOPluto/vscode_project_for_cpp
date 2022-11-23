// #include <iostream>
// #include <stdio.h>
// #include <string>
// #include <algorithm>
// #include <cstdio>
// #include <vector>
// using namespace std;

// /* 请在这里填写答案 */

// class BigInt{
//     public:
//     vector<int> num;
// };

// istream & operator>>(istream &in, BigInt &A){
//     char ch;
//     while((ch = getchar()) != '\n'){
//         A.num.push_back(ch - '0');
//     }
//     cin.get();
//     reverse(A.num.begin(), A.num.end());

//     return in;
// }

// ostream & operator<<(ostream &out, BigInt &A){
//     for(int i = A.num.size() - 1;i >= 0;i--){
//         out << A.num[i];
//     }
//     return out;
// }

// BigInt & operator+(const BigInt& A, const BigInt& B){
//     BigInt* C = new BigInt();
//     int t = 0;
//     if(A.num.size() > B.num.size())
//         for(int i = 0;i < A.num.size();i++){
//             if(i < B.num.size()) t += B.num[i];
//             t += A.num[i];
//             C->num.push_back(t % 10);
//             t /= 10;
//         }
//     else
//         for(int i = 0;i < B.num.size();i++){
//             if(i < A.num.size()) t += A.num[i];
//             t += B.num[i];
//             C->num.push_back(t % 10);
//             t /= 10;
//         }
//     if(t) C->num.push_back(t);
//     return *C;
// }

// int main(){
//     BigInt a, b, c;
//     cin>>a>>b;
//      c=a+b;
//     cout<<a<<"+"<<b<<"="<<c<<endl;
//     return 0;
// }


#include <iostream>

using namespace std;

int main(){
    char ss[10];
    scanf("%s", ss + 1);
    cin.get();
    cout << ss + 1;
    return 0;
}