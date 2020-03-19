/*************************************************************************
	> File Name: haizei536.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月19日 星期四 14时11分29秒
 ************************************************************************/

#include <iostream>
using namespace std;

int ans, tmp;
char mmap[105][105];
int dir[4][2] = {
    1, 0, 0, 1, -1, 0, 0, -1
};

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '1') {
            tmp++;
            mmap[xx][yy] = '0';
            func(xx, yy);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    for (int i = 1; i <= n; i++) {
        scanf("%s", &(mmap[i][1]));
        getchar();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == '1') {
                mmap[i][j] = '0';
                tmp = 1;
                func(i, j);
                ans = max(ans, tmp);
                //if (ans < tmp) ans = tmp;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
