// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// #include <stack>
// #include <queue>

// using namespace std;

// const int N = 510;

// priority_queue<int> heap;

// int n, m;
// int g[N][N];
// int dist[N];
// bool st[N];

// void dijkstra(){
//     dist[1] = 0;
//     for(int i = 0;i < n - 1;i++){
//         int t = -1;
//         for(int j = 1;j <= n;j++){
//             if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
//         }

//         for(int j = 1;j <= n;j++)
//             dist[j] = min(dist[j], dist[t] + g[t][j]);
        
//         st[t] = true;
//     }
// }

// int main(){
//     scanf("%d%d", &n, &m);
//     memset(g, 0x3f, sizeof g);
//     memset(dist, 0x3f, sizeof dist);
//     while(m --){
//         int a, b, c;
//         cin >> a >> b >> c;
//         g[a][b] = min(g[a][b], c);
//     }
//     dijkstra();

//     cout << dist[n] << endl;

//     return 0;
// }



#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int N = 510;

int g[N][N];
int dist[N];
bool st[N];
int n, m;

void find(){
    dist[1] = 0;
    for(int i = 0;i < n - 1;i++){
        int t = -1;
        for(int j = 1;j <= n;j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        st[t] = true;
        for(int j = 1;j <= n;j++){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(dist, 0x3f, sizeof dist);
    memset(g, 0x3f, sizeof g);
    while(m --){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    find();

    if(dist[n] != 0x3f3f3f3f) cout << dist[n];
    else puts("-1");

    return 0;
}