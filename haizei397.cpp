/*************************************************************************
	> File Name: haizei397.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月19日 星期四 13时38分33秒
 ************************************************************************/

#include <iostream>
using namespace std;

int mmap[105][105];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int ans;

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy]) {
            mmap[xx][yy] = 0;
            func(xx, yy);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mmap[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == 0) continue;
            ans++;
            func(i, j);
        }
    }
    printf("%d\n", ans);
    return 0;
}
