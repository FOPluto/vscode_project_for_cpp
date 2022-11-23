#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef pair<int, int> PII;
PII                    arr[10];
int                    num;
int                    time[100];
bool                   time02[100];
int                    main()
{
    bool flag01 = true;
    int  temp   = 0;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i].first;
        if (temp == 0)
            temp = arr[i].first;
        else if (arr[i].first != ++temp) {
            flag01 = false;
        }
    }
    temp        = 0;
    bool flag02 = true;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i].second;
        if (temp == 0)
            temp = arr[i].second;
        else if (arr[i].second != temp) {
            flag02 = false;
        }
    }

    if (flag01 && flag02 && arr[4].first == 14) {
        cout << "ROYAL FLUSH" << endl;
        return 0;
    }
    else if (flag01 && flag02) {
        cout << "STRAIGHT FLUSH" << endl;
        return 0;
    }
    else {
        for (int i = 0; i < 5; i++) {
            time[arr[i].first]++;
        }
        for (int i = 0; i <= 14; i++) {
            time02[time[i]] = true;
        }
    }

    if (time02[4])
        cout << "FOUR OF A KIND" << endl;
    else if (time02[3] && time02[2])
        cout << "FULL HOUSE" << endl;
    else if (flag02)
        cout << "FLUSH" << endl;
    else if (flag01)
        cout << "STRAIGHT" << endl;
    else
        cout << "FOLD" << endl;
    return 0;
}