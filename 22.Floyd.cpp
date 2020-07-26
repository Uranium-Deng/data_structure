/*************************************************************************
	> File Name: 1.Floyd.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月26日 星期日 10时05分22秒
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
#include <cstring>
#include <vector>
using namespace std;

int n, m, s, ans[1005][1005];

int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ans[a][b] = c;
    }
    for (int i = 1; i <= n; i++) {
        ans[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << ans[s][i];
    }
    cout << endl;
    return 0;
}
