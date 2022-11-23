


// // #include <iostream>
// // #include <cstdio>
// // #include <cstring>

// // using namespace std;

// // bool is_primer(int num){
// //     for(int i = 2;i <= num / i;i++){
// //         if(num % i == 0) return false;
// //     }
// //     return true;
// // }

// // const int N = 10000;
// // bool is_pri[N];
// // int ans[N];

// // int main(){
// //     for(int i = 2;i <= N;i++){
// //         is_pri[i] = is_primer(i);
// //     }
    
// //     int n, m;
// //     cin >> n >> m;
    
// //     int sum = 0;
// //     int res = 0;
    
// //     for(int i = n;i >= 2 && sum < m;i--){
// //         if(is_pri[i]){
// //             ans[sum++] = i;
// //             res += i;
// //         }
// //     }
// //     for(int i = 1;i < sum;i++){
// //         if(i != 1) cout << "+";
// //         cout << ans[i];
// //     }
// //     printf("=%d\n", res);
// //     return 0;
// // }


// // #include <iostream>
// // #include <cstdio>
// // #include <cstring>
// // #include <algorithm>
// // #include <vector>

// // using namespace std;

// // const int N = 100050;
// // int primer[N];
// // bool st[N];
// // int cnt;

// // int main(){
// //     st[1]= true;
// //     for(int i = 2;i <= 40000;i++){
// //         if(!st[i]) primer[cnt ++] = i;
// //         for(int j = 0;primer[j] < 40000 / i;j++){
// //             st[primer[j] * i] = true;
// //             if(i % primer[j] == 0) break;
// //         }
// //     }
    
// //     int a = 0;
// //     while(cin >> a){
// //         if(!a) break;
// //         int ans_num = 0;
// //         for(int i = 2;i <= a / 2;i++){
// //             if(!st[i] && !st[a - i]) ans_num++;
// //         }
// //         cout << ans_num << endl;
// //      }
// //     return 0;
// // }

// // #include <iostream>
// // #include <cstdio>
// // #include <cstring>
// // #include <algorithm>
// // #include <vector>

// // using namespace std;

// // const int N = 40050;
// // int primer[N];
// // bool st[N];
// // int cnt;

// // int main(){
// //     st[1]= true;
// //     st[0] = true;
// //     for(int i = 2;i <= 40000;i++){
// //         if(!st[i]) primer[cnt ++] = i;
// //         for(int j = 0;primer[j] < 40000 / i;j++){
// //             st[primer[j] * i] = true;
// //             if(i % primer[j] == 0) break;
// //         }
// //     }
    
// //     int a = 0;
// //     while(cin >> a){
// //         if(!a) break;
// //         int ans_num = 0;
// //         for(int i = 2;i <= a / 2;i++){
// //             if(!st[i] && !st[a - i]) ans_num++;
// //         }
// //         cout << ans_num << endl;
// //      }
    
// //     return 0;
// // }


// /////test
// // #include <cstdio>
// // #include <iostream>

// // using namespace std;

// // int main(){
// //     int* p, *a;
// //     return 0;
// // }






// // #include <cstring>
// // #include <cstdio>
// // #include <algorithm>
// // #include <iostream>

// // using namespace std;

// // typedef pair<double, string> PII;

// // const int N = 10010;

// // PII arr[N];

// // int main(){
// //     int n = 0;
// //     cin >> n;
// //     for(int i = 0;i < n;i++){
// //         string a;
// //         cin.get();
// //         getline(cin, a);
        
// //         arr[i].second = a;
// //         cin >> arr[i].first;
// //     }
// //     sort(arr, arr + n, [](const PII p1, const PII p2){
// //         return p1.first < p2.first;
// //     });

// //     cout << arr[0].first << "," << arr[0].second << endl;

// //     cout << arr[n - 1].first << "," << arr[n - 1].second << endl;
// //     return 0;
// // }


// // #include <cstring>
// // #include <algorithm>
// // #include <cstdio>
// // #include <iostream>

// // using namespace std;

// // const int N = 1010;

// // bool arr[N];


// // int main(){
// //     int n;
// //     cin >> n;
// //     int num = n, idx = -1;
// //     while(num > 1){
// //         for(int j = 0;j < 3;j++){
// //             idx = (idx + 1) % n;
// //             if(arr[idx]) j--;  
// //         }
// //         arr[idx] = true;
// //         num--;
// //     }
// //     int res = -1;
// //     for(int i = 0;i < n;i++){
// //         if(!arr[i]) res = i;
// //     }
// //     cout << res + 1 << endl;
// //     return 0;
// // }


// // #include <iostream>
// // #include <algorithm>

// // using namespace std;

// // int main(){
// //     int a = 0, b = 1, c = 2;
// //     // cout << (a, b, c) << (a, b, c) << (a, b, c);
// //     float *fp [25][10];
// //     float (* fpt)[25][10];
// //     auto test = new float[10][25][10];
// //     fpt = test;
// //     delete test;
// //     return 0;
// // }


// // #include <cstdio>
// // #include <iostream>
// // #include <cstring>
// // #include <vector>
// // #include <unordered_map>
// // #include <map>
// // #include <set>
// // #include <queue>

// // using namespace std;

// // int value;   //定义全局变量value

// // int main() 
// // {
// // 	int value;  //定义局部变量value
// // 	value = 100;
// // 	::value = 1000;
// // 	cout << "local value : " << value << endl;
// // 	cout << "global value : " << ::value << endl;
// // 	return 0;
// // }


// // #include <cstdio>
// // #include <iostream>
// // #include <cstring>
// // #include <vector>
// // #include <unordered_map>
// // #include <map>
// // #include <set>
// // #include <queue>


// // using namespace std;


// // int main(){
// // 	float num = 0;
// // 	cin >> num;

// // 	if(num < 0) puts("Invalid Value!");
// // 	else if(num <= 50){
// // 		float ans = 0.53 * num;
// // 		printf("%.2f\n", ans);
// // 	} else {
// // 		float ans = 0.53 * 50 + 0.58 * num;
// // 		printf("%.2f\n", ans);
// // 	}
// // 	return 0;
// // }

// #define CRT_SECURE_NO_WARINGS

// #include <cstdio>
// #include <iostream>
// #include <cstring>
// #include <vector>
// #include <unordered_map>
// #include <map>
// #include <set>
// #include <queue>


// using namespace std;

// const int N = 100010;

// int p[N];

// int n, m;

// int find(int num){
// 	if(p[num] != num) p[num] = find(p[num]);
// 	return p[num];
// }

// int ans;

// int main(){
// 	scanf("%d%d", &n, &m);
// 	for(int i = 1;i <= n; i++){
// 		p[i] = i;
// 	}

// 	while(m --){
// 		int a, b, c;
// 		scanf("%d%d%d", &a, &b, &c);
// 		if(a == 1) p[find(b)] = find(c);
// 		else 
// 			if(find(c) == find(b)) ans ++;
// 	}
// 	return 0;
// }


#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>


using namespace std;

const int N = 100010;

int arr[N], n, m;

int MaxSub(){
	int max_num = -100010;

	int current_num = 0;
	for(int i = 0;i < n;i++){

		current_num += arr[i];
		if(current_num > max_num) max_num = current_num;
		else if(current_num < 0) current_num = 0;
		cout << max_num << endl;
	}
	return max_num;
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++) scanf("%d", &arr[i]);

	int ans = MaxSub();

	printf("%d\n", ans);
	return 0;
}
