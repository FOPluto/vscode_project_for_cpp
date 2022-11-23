// #include<cstdio>
// #include<algorithm>
// #include<iostream>
// #include<cstring>

// using namespace std;

// const int N = 510, INF = 0x3f3f3f3f;

// int n, m;
// int g[N][N];
// int dist[N];
// bool st[N];

// int prim() {
// 	memset(dist, 0x3f, sizeof dist);

// 	int res = 0;
// 	for (int i = 0; i < n; i++) {
// 		int t = -1;
// 		for (int j = 1; j <= n; j++) {
// 			if (!st[j] && (t == -1 || dist[t] > dist[j]))
// 				t = j;
// 		}
// 		if (i && dist[t] == INF) {
// 			return INF;
// 		}

// 		if (i) res += dist[t];

// 		for (int j = 1; j <= n; j++) {
// 			dist[j] = min(dist[j], g[t][j]);
// 		}

// 		st[t] = true;
// 	}
// 	return res;
// }

// int main() {
// 	scanf("%d%d", &n, &m);

// 	memset(g, 0x3f, sizeof g);

// 	while (m--) {
// 		int a, b, c;
// 		scanf("%d%d%d", &a, &b, &c);
// 		g[a][b] = g[b][a] = min(c, g[a][b]);
// 	}

// 	int t = prim();

// 	if (t == INF) puts("impossible");
// 	else printf("%d", t);
// 	return 0;
// }

//先叠加在更新
// #include<cstdio>
// #include<iostream>
// #include<cstring>
// #include<algorithm>

// using namespace std;

// const int N = 510;
// const int IMF = 0x3f3f3f3f;

// int g[N][N];
// int dist[N];
// int n, m;
// bool st[N];

// int prim(){
// 	memset(dist, 0x3f, sizeof dist);
// 	int ans = 0;
// 	for(int i = 0;i < n;i++){
// 		int t = -1;
// 		for(int j = 1;j <= n;j++){
// 			if(!st[j] && (t == -1 && dist[t] > dist[j]))
// 				t = j;
// 			if(i && dist[t] == IMF) return IMF;

// 			if(i) ans += dist[t];

// 			for(int j = 1;j <= n;j++){
// 				dist[j] = min(dist[j], g[t][j]);
// 			}
// 		}
// 	}
// 	return ans;
// }

// int main(){
// 	memset(g, 0x3f, sizeof g);
// 	scanf("%d%d", &n, &m);
// 	while(m --){
// 		int a, b, c;
// 		scanf("%d%d%d", &a, &b, &c);
// 		g[a][b] = g[b][a] = min(g[a][b], c);
// 	}
// 	int t = prim();

// 	if(t == IMF) puts("impossible");
// 	else printf("%d\n", t);
// }

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>

// using namespace std;

// const int N   = 510;
// const int INF = 0x3f3f3f3f;

// int  n, m;
// int  dist[N];
// int  g[N][N];
// bool st[N];

// int prim()
// {
//     memset(dist, 0x3f, sizeof dist);
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         int t = -1;
//         for (int j = 1; j <= n; j++)
//             if (!st[j] && (t == -1 || dist[t] > dist[j]))
//                 t = j;

//         if (i && dist[t] == INF)
//             return INF;

//         if (i)
//             ans += dist[t];

//         for (int j = 1; j <= n; j++) {
//             dist[j] = min(dist[j], g[t][j]);
//         }
//         st[t] = true;
//     }
//     return ans;
// }

// int main()
// {
//     memset(g, 0x3f, sizeof g);
//     scanf("%d%d", &n, &m);
//     while (m--) {
//         int a, b, c;
//         scanf("%d%d%d", &a, &b, &c);
//         g[a][b] = g[b][a] = min(g[a][b], c);
//     }
//     int t = prim();

//     if (t == INF)
//         puts("impossible");
//     else
//         printf("%d\n", t);
//     return 0;
// }

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int num = 0;
int ans = 0;
int dp[110];

void run(int n)
{
    if (n <= 1) {
        ans++;
        return;
    }
    if (dp[n] > 0) {
        ans += dp[n];
    }
    if (num == 2) {
        num = 0;
        run(n - 1);
        dp[n] += ans;
    }
    else {
        num++;
        run(n - 2);
        dp[n] += ans;
        num = 0;
        run(n - 1);
        dp[n] += ans;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    run(n);
    printf("%d\n", ans);
    return 0;
}