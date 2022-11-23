#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 10010;

typedef pair<string, int> PII;

PII name[N];
PII score[N];

int n, m, x;

int main()
{
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i++) {
        cin >> name[i].first;
    }

    for (int i = 0; i < m; i++) {
        cin >> score[i].first;
        scanf("%d", &score[i].second);
    }

    while (x--) {
        string nameIn;
        cin >> nameIn;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (nameIn == name[i].first) {
                flag = true;
                break;
            }
        }
        string ti, output;
        cin >> ti >> output;
        // scanf("%s%s", &ti, &output);
        if (!flag || output == "WA")
            continue;
        else {
            int scoreA = 0;
            for (int i = 0; i < m; i++) {
                if (score[i].first == ti) {
                    scoreA = score[i].second;
                }
            }
            for (int i = 0; i < n; i++) {
                if (name[i].first == nameIn) {
                    name[i].second += scoreA;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << name[i].first;
        printf(" %d\n", name[i].second);
    }
    return 0;
}