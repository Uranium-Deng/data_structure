/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年09月13日 星期日 10时09分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_N 10000
#define MAX_M 20000

int n, m, s;
int edg[MAX_M + 5][3], dis[MAX_N + 5];

int main() {
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        cin >> edg[i][0] >> edg[i][1] >> edg[i][2];
    }
    dis[s] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dis[edg[j][1]] = min(dis[edg[j][0]] + edg[j][2], dis[edg[j][1]]);
        }
    }

    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << dis[i];
    }
    cout << endl;

    return 0;
}
